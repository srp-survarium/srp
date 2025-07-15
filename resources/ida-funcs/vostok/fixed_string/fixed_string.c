void __userpurge vostok::fixed_string<512>::fixed_string<512>(
        vostok::fixed_string<512> *this@<ecx>,
        int a2@<esi>,
        char **begin_src,
        const char **end_src)
{
  unsigned int v4; // [esp+0h] [ebp-4h] BYREF

  v4 = 512;
  vostok::buffer_string::buffer_string((char *)(a2 + 12), &v4, (vostok::buffer_string *)a2, begin_src, end_src);
}


void __usercall vostok::fixed_string<16>::fixed_string<16>(
        vostok::fixed_string<16> *this@<esi>,
        const vostok::fixed_string<16> *src@<eax>)
{
  char *m_end; // ecx
  unsigned int v3; // [esp+0h] [ebp-Ch] BYREF
  char *m_begin; // [esp+4h] [ebp-8h] BYREF
  char *v5; // [esp+8h] [ebp-4h] BYREF

  m_end = src->m_end;
  m_begin = src->m_begin;
  v5 = m_end;
  v3 = 16;
  vostok::buffer_string::buffer_string(this->m_buffer, &v3, this, &m_begin, (const char **)&v5);
}


void __userpurge vostok::fixed_string<16>::fixed_string<16>(
        vostok::fixed_string<16> *this@<ecx>,
        vostok::buffer_string *a2@<esi>,
        char *src)
{
  int v3; // [esp+0h] [ebp-4h] BYREF

  vostok::buffer_string::buffer_string(a2 + 1, a2, (char *)&v3, src, (const char *)0x10);
}


void __usercall vostok::fixed_string<256>::fixed_string<256>(
        vostok::fixed_string<256> *this@<esi>,
        const vostok::fixed_string<256> *src@<eax>)
{
  char *m_end; // ecx
  unsigned int v3; // [esp+0h] [ebp-Ch] BYREF
  char *m_begin; // [esp+4h] [ebp-8h] BYREF
  char *v5; // [esp+8h] [ebp-4h] BYREF

  m_end = src->m_end;
  m_begin = src->m_begin;
  v5 = m_end;
  v3 = 256;
  vostok::buffer_string::buffer_string(this->m_buffer, &v3, this, &m_begin, (const char **)&v5);
}


void __userpurge vostok::fixed_string<256>::fixed_string<256>(
        vostok::fixed_string<256> *this@<ecx>,
        vostok::buffer_string *a2@<esi>,
        char *src)
{
  int v3; // [esp+0h] [ebp-4h] BYREF

  vostok::buffer_string::buffer_string(a2 + 1, a2, (char *)&v3, src, (const char *)0x100);
}


void __usercall vostok::fixed_string<260>::fixed_string<260>(
        vostok::fixed_string<260> *this@<esi>,
        const vostok::fixed_string<260> *src@<eax>)
{
  char *m_end; // ecx
  unsigned int v3; // [esp+0h] [ebp-Ch] BYREF
  char *m_begin; // [esp+4h] [ebp-8h] BYREF
  char *v5; // [esp+8h] [ebp-4h] BYREF

  m_end = src->m_end;
  m_begin = src->m_begin;
  v5 = m_end;
  v3 = 260;
  vostok::buffer_string::buffer_string(this->m_buffer, &v3, this, &m_begin, (const char **)&v5);
}


void __userpurge vostok::fixed_string<260>::fixed_string<260>(
        vostok::fixed_string<260> *this@<ecx>,
        vostok::buffer_string *a2@<esi>,
        char *src)
{
  char buffer[4]; // [esp+0h] [ebp-4h] BYREF

  vostok::buffer_string::buffer_string(a2 + 1, a2, buffer, src, (const char *)0x104);
}


void __usercall vostok::fixed_string<32>::fixed_string<32>(
        vostok::fixed_string<32> *this@<esi>,
        const vostok::fixed_string<32> *src@<eax>)
{
  char *m_end; // ecx
  unsigned int v3; // [esp+0h] [ebp-Ch] BYREF
  char *m_begin; // [esp+4h] [ebp-8h] BYREF
  char *v5; // [esp+8h] [ebp-4h] BYREF

  m_end = src->m_end;
  m_begin = src->m_begin;
  v5 = m_end;
  v3 = 32;
  vostok::buffer_string::buffer_string(this->m_buffer, &v3, this, &m_begin, (const char **)&v5);
}


void __userpurge vostok::fixed_string<32>::fixed_string<32>(
        vostok::fixed_string<32> *this@<ecx>,
        vostok::buffer_string *a2@<esi>,
        char *src)
{
  int v3; // [esp+0h] [ebp-4h] BYREF

  vostok::buffer_string::buffer_string(a2 + 1, a2, (char *)&v3, src, (const char *)0x20);
}


void __usercall vostok::fixed_string<512>::fixed_string<512>(
        vostok::fixed_string<512> *this@<esi>,
        const vostok::fixed_string<512> *src@<eax>)
{
  char *m_end; // ecx
  unsigned int v3; // [esp+0h] [ebp-Ch] BYREF
  char *m_begin; // [esp+4h] [ebp-8h] BYREF
  char *v5; // [esp+8h] [ebp-4h] BYREF

  m_end = src->m_end;
  m_begin = src->m_begin;
  v5 = m_end;
  v3 = 512;
  vostok::buffer_string::buffer_string(this->m_buffer, &v3, this, &m_begin, (const char **)&v5);
}


void __userpurge vostok::fixed_string<512>::fixed_string<512>(
        vostok::fixed_string<512> *this@<ecx>,
        vostok::buffer_string *a2@<esi>,
        char *src)
{
  int v3; // [esp+0h] [ebp-4h] BYREF

  vostok::buffer_string::buffer_string(a2 + 1, a2, (char *)&v3, src, (const char *)0x200);
}


void __usercall vostok::fixed_string<64>::fixed_string<64>(
        vostok::fixed_string<64> *this@<esi>,
        const vostok::fixed_string<64> *src@<eax>)
{
  char *m_end; // ecx
  unsigned int v3; // [esp+0h] [ebp-Ch] BYREF
  char *m_begin; // [esp+4h] [ebp-8h] BYREF
  char *v5; // [esp+8h] [ebp-4h] BYREF

  m_end = src->m_end;
  m_begin = src->m_begin;
  v5 = m_end;
  v3 = 64;
  vostok::buffer_string::buffer_string(this->m_buffer, &v3, this, &m_begin, (const char **)&v5);
}


void __userpurge vostok::fixed_string<64>::fixed_string<64>(
        vostok::fixed_string<64> *this@<ecx>,
        vostok::buffer_string *a2@<esi>,
        char *src)
{
  int v3; // [esp+0h] [ebp-4h] BYREF

  vostok::buffer_string::buffer_string(a2 + 1, a2, (char *)&v3, src, (const char *)0x40);
}


void __usercall vostok::fixed_string<128>::fixed_string<128>(
        vostok::fixed_string<128> *this@<esi>,
        const vostok::fixed_string<128> *src@<eax>)
{
  char *m_end; // ecx
  unsigned int v3; // [esp+0h] [ebp-Ch] BYREF
  char *m_begin; // [esp+4h] [ebp-8h] BYREF
  char *v5; // [esp+8h] [ebp-4h] BYREF

  m_end = src->m_end;
  m_begin = src->m_begin;
  v5 = m_end;
  v3 = 128;
  vostok::buffer_string::buffer_string(this->m_buffer, &v3, this, &m_begin, (const char **)&v5);
}


void __userpurge vostok::fixed_string<128>::fixed_string<128>(
        vostok::fixed_string<128> *this@<ecx>,
        vostok::buffer_string *a2@<esi>,
        char *src)
{
  int v3; // [esp+0h] [ebp-4h] BYREF

  vostok::buffer_string::buffer_string(a2 + 1, a2, (char *)&v3, src, (const char *)0x80);
}
