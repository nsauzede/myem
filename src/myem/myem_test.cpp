/*
 * Copyright(c) 2019 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "myem/myem.h"
#include "testing/testing.h"

TEST_F(myem, Myem) {
	TEST_LOG("Testing MyEm..\n");
	MyEm m;
	TEST_LOG("Testing MyEm config..\n");
	m.Load("{\"bios\":\"bios.bin\"}");
	TEST_LOG("Testing MyEm run..\n");
	m.Run();
}
