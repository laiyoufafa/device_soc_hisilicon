/*
 * Copyright (C) 2022 HiSilicon (Shanghai) Technologies CO., LIMITED.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "hi_osal.h"
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/spinlock.h>
#include <linux/slab.h>
#include <linux/kallsyms.h>

int osal_spin_lock_init(osal_spinlock *lock)
{
    spinlock_t *p = NULL;

    if (lock == NULL) {
        osal_printk("%s - parameter invalid!\n", __FUNCTION__);
        return -1;
    }
    p = (spinlock_t *)kmalloc(sizeof(spinlock_t) + 8 + 8, GFP_KERNEL); // 8 is malloc size
    if (p == NULL) {
        osal_printk("%s - kmalloc error!\n", __FUNCTION__);
        return -1;
    }
    spin_lock_init(p);
    lock->lock = p;
    return 0;
}
EXPORT_SYMBOL(osal_spin_lock_init);

void osal_spin_lock(osal_spinlock *lock)
{
    spinlock_t *p = NULL;

    if (lock == NULL) {
        osal_printk("%s - parameter invalid!\n", __FUNCTION__);
        return;
    }

    p = (spinlock_t *)(lock->lock);
    spin_lock(p);
}
EXPORT_SYMBOL(osal_spin_lock);

int osal_spin_trylock(osal_spinlock *lock)
{
    spinlock_t *p = NULL;

    if (lock == NULL) {
        osal_printk("%s - parameter invalid!\n", __FUNCTION__);
        return -1;
    }

    p = (spinlock_t *)(lock->lock);

    return spin_trylock(p);
}
EXPORT_SYMBOL(osal_spin_trylock);

void osal_spin_unlock(osal_spinlock *lock)
{
    spinlock_t *p = NULL;

    if (lock == NULL) {
        osal_printk("%s - parameter invalid!\n", __FUNCTION__);
        return;
    }

    p = (spinlock_t *)(lock->lock);
    spin_unlock(p);
}
EXPORT_SYMBOL(osal_spin_unlock);

void osal_spin_lock_irqsave(osal_spinlock *lock, unsigned long *flags)
{
    spinlock_t *p = NULL;
    unsigned long f;

    if ((lock == NULL) || (flags == NULL)) {
        osal_printk("%s - parameter invalid!\n", __FUNCTION__);
        return;
    }

    p = (spinlock_t *)(lock->lock);
    spin_lock_irqsave(p, f);

    *flags = f;
}
EXPORT_SYMBOL(osal_spin_lock_irqsave);

void osal_spin_unlock_irqrestore(osal_spinlock *lock, unsigned long *flags)
{
    spinlock_t *p = NULL;

    if ((lock == NULL) || (flags == NULL)) {
        osal_printk("%s - parameter invalid!\n", __FUNCTION__);
        return;
    }

    p = (spinlock_t *)(lock->lock);
    spin_unlock_irqrestore(p, *flags);
}
EXPORT_SYMBOL(osal_spin_unlock_irqrestore);

void osal_spin_lock_destory(osal_spinlock *lock)
{
    spinlock_t *p = NULL;

    if (lock == NULL) {
        osal_printk("%s - parameter invalid!\n", __FUNCTION__);
        return;
    }

    p = (spinlock_t *)(lock->lock);
    kfree(p);
    lock->lock = NULL;
}
EXPORT_SYMBOL(osal_spin_lock_destory);
