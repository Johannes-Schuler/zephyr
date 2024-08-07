/*
 * Copyright (c) 2018 - 2021 Antmicro <www.antmicro.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT litex_vexriscv_intc0

#include <zephyr/kernel.h>
#include <zephyr/arch/cpu.h>
#include <zephyr/irq.h>
#include <zephyr/device.h>
#include <zephyr/types.h>
#include <zephyr/arch/riscv/irq.h>

#define IRQ_MASK		DT_INST_REG_ADDR_BY_NAME(0, irq_mask)
#define IRQ_PENDING		DT_INST_REG_ADDR_BY_NAME(0, irq_pending)

<<<<<<< HEAD
#define TIMER0_IRQ		DT_IRQN(DT_INST(0, litex_timer0))
#define UART0_IRQ		DT_IRQN(DT_INST(0, litex_uart0))

#define ETH0_IRQ		DT_IRQN(DT_INST(0, litex_eth0))

#define I2S_RX_IRQ		DT_IRQN(DT_NODELABEL(i2s_rx))
#define I2S_TX_IRQ		DT_IRQN(DT_NODELABEL(i2s_tx))

#define GPIO_IRQ		DT_IRQN(DT_NODELABEL(gpio_in))

=======
>>>>>>> 72dd6bb55432e5fd641ac3b93179a1186ed97911
static inline void vexriscv_litex_irq_setmask(uint32_t mask)
{
	__asm__ volatile ("csrw %0, %1" :: "i"(IRQ_MASK), "r"(mask));
}

static inline uint32_t vexriscv_litex_irq_getmask(void)
{
	uint32_t mask;

	__asm__ volatile ("csrr %0, %1" : "=r"(mask) : "i"(IRQ_MASK));
	return mask;
}

static inline uint32_t vexriscv_litex_irq_pending(void)
{
	uint32_t pending;

	__asm__ volatile ("csrr %0, %1" : "=r"(pending) : "i"(IRQ_PENDING));
	return pending;
}

static inline void vexriscv_litex_irq_setie(uint32_t ie)
{
	if (ie) {
		__asm__ volatile ("csrrs x0, mstatus, %0"
				:: "r"(MSTATUS_IEN));
	} else {
		__asm__ volatile ("csrrc x0, mstatus, %0"
				:: "r"(MSTATUS_IEN));
	}
}

<<<<<<< HEAD
=======
#define LITEX_IRQ_ADD_HELPER(n)                                                                    \
	if (irqs & (1 << DT_IRQN(n))) {                                                            \
		ite = &_sw_isr_table[DT_IRQN(n)];                                                  \
		ite->isr(ite->arg);                                                                \
	}

#define LITEX_IRQ_ADD(n) IF_ENABLED(DT_IRQ_HAS_IDX(n, 0), (LITEX_IRQ_ADD_HELPER(n)))

>>>>>>> 72dd6bb55432e5fd641ac3b93179a1186ed97911
static void vexriscv_litex_irq_handler(const void *device)
{
	struct _isr_table_entry *ite;
	uint32_t pending, mask, irqs;

	pending = vexriscv_litex_irq_pending();
	mask = vexriscv_litex_irq_getmask();
	irqs = pending & mask;

<<<<<<< HEAD
#ifdef CONFIG_LITEX_TIMER
	if (irqs & (1 << TIMER0_IRQ)) {
		ite = &_sw_isr_table[TIMER0_IRQ];
		ite->isr(ite->arg);
	}
#endif

#ifdef CONFIG_UART_INTERRUPT_DRIVEN
	if (irqs & (1 << UART0_IRQ)) {
		ite = &_sw_isr_table[UART0_IRQ];
		ite->isr(ite->arg);
	}
#endif

#ifdef CONFIG_ETH_LITEETH
	if (irqs & (1 << ETH0_IRQ)) {
		ite = &_sw_isr_table[ETH0_IRQ];
		ite->isr(ite->arg);
	}
#endif

#ifdef CONFIG_I2S
	if (irqs & (1 << I2S_RX_IRQ)) {
		ite = &_sw_isr_table[I2S_RX_IRQ];
		ite->isr(ite->arg);
	}
	if (irqs & (1 << I2S_TX_IRQ)) {
		ite = &_sw_isr_table[I2S_TX_IRQ];
		ite->isr(ite->arg);
	}
#endif

	if (irqs & (1 << GPIO_IRQ)) {
		ite = &_sw_isr_table[GPIO_IRQ];
		ite->isr(ite->arg);
	}
=======
	DT_FOREACH_STATUS_OKAY_NODE(LITEX_IRQ_ADD);
>>>>>>> 72dd6bb55432e5fd641ac3b93179a1186ed97911
}

void arch_irq_enable(unsigned int irq)
{
	vexriscv_litex_irq_setmask(vexriscv_litex_irq_getmask() | (1 << irq));
}

void arch_irq_disable(unsigned int irq)
{
	vexriscv_litex_irq_setmask(vexriscv_litex_irq_getmask() & ~(1 << irq));
}

int arch_irq_is_enabled(unsigned int irq)
{
	return vexriscv_litex_irq_getmask() & (1 << irq);
}

static int vexriscv_litex_irq_init(const struct device *dev)
{
	__asm__ volatile ("csrrs x0, mie, %0"
			:: "r"(1 << RISCV_IRQ_MEXT));
	vexriscv_litex_irq_setie(1);
	IRQ_CONNECT(RISCV_IRQ_MEXT, 0, vexriscv_litex_irq_handler,
			NULL, 0);

	return 0;
}

DEVICE_DT_INST_DEFINE(0, vexriscv_litex_irq_init, NULL, NULL, NULL,
		      PRE_KERNEL_1, CONFIG_INTC_INIT_PRIORITY, NULL);
