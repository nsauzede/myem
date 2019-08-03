/*
 * Copyright(c) 2019 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "myem/myem.h"
#include "testing/testing.h"

void myem_TestMyem(void *t) {
	testing_Logf(t, "Testing MyEm..\n");
	MyEm m;
	testing_Logf(t, "Testing MyEm config..\n");
	m.Load("{\"bios\":\"bios.bin\"}");
	testing_Logf(t, "Testing MyEm run..\n");
	m.Run();
}
