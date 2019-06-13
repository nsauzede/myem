/*
 * Copyright(c) 2019 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stdio.h>

#include "myem.h"
#include "testing/testing.h"

void myem_TestMyem(void *t) {
	printf("%s: t=%p\n", __func__, t);
	MyEm m;
}
