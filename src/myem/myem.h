/*
 * Copyright(c) 2019 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <string>

class MyEm {
private:
//	std_vector<unsigned char> m_bios;
	unsigned char *m_bios;
	unsigned long m_bios_size;
public:
	MyEm();
	~MyEm();
	void Load(const std::string& config);
	void Run();
};
