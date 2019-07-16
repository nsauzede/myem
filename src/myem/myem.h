/*
 * Copyright(c) 2019 Nicolas Sauzede (nsauzede@laposte.net)
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <string>

class MyEm {
private:
//	std_vector<unsigned char> m_bios;
	unsigned char *m_bios;
	uint32_t m_bios_size;
	uint32_t m_bios_start;
	uint16_t m_cs;
	uint16_t m_ip;
public:
	MyEm();
	~MyEm();
	void Load(const std::string& config);
	void Run();
};
