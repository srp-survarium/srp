void __usercall vostok::fixed_string<8>::fixed_string<8>(vostok::fixed_string<8> *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)a2 = a2 + 12;
  *(_DWORD *)(a2 + 4) = a2 + 12;
  *(_DWORD *)(a2 + 8) = a2 + 20;
  *(_BYTE *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 12) = 0;
}


void __usercall vostok::fixed_string<16>::fixed_string<16>(
        vostok::fixed_string<16> *this@<esi>,
        const vostok::fixed_string<16> *src@<eax>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // edi

  m_begin = (unsigned __int8 *)src->m_begin;
  v3 = src->m_end - src->m_begin;
  this->m_max_end = (char *)&this[1];
  v4 = v3;
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  memcpy((unsigned __int8 *)this->m_buffer, m_begin, v3);
  this->m_end += v4;
  *this->m_end = 0;
}


void __thiscall vostok::fixed_string<16>::fixed_string<16>(vostok::fixed_string<16> *this, const char *src)
{
  this->m_max_end = (char *)&this[1];
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  this->m_buffer[0] = 0;
  vostok::buffer_string::operator+=(&this->vostok::buffer_string, src);
}


void __usercall vostok::fixed_string<16>::fixed_string<16>(vostok::fixed_string<16> *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)a2 = a2 + 12;
  *(_DWORD *)(a2 + 4) = a2 + 12;
  *(_DWORD *)(a2 + 8) = a2 + 28;
  *(_BYTE *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 12) = 0;
}


void __usercall vostok::fixed_string<256>::fixed_string<256>(
        vostok::fixed_string<256> *this@<esi>,
        const vostok::fixed_string<256> *src@<eax>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // edi

  m_begin = (unsigned __int8 *)src->m_begin;
  v3 = src->m_end - src->m_begin;
  this->m_max_end = (char *)&this[1];
  v4 = v3;
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  memcpy((unsigned __int8 *)this->m_buffer, m_begin, v3);
  this->m_end += v4;
  *this->m_end = 0;
}


void __usercall vostok::fixed_string<256>::fixed_string<256>(
        vostok::fixed_string<256> *this@<esi>,
        const char *src@<edx>)
{
  this->m_max_end = (char *)&this[1];
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  this->m_buffer[0] = 0;
  vostok::buffer_string::operator+=(this, src);
}


void __thiscall vostok::fixed_string<256>::fixed_string<256>(vostok::fixed_string<256> *this)
{
  char *m_buffer; // ecx

  m_buffer = this->m_buffer;
  this->m_begin = m_buffer;
  this->m_end = m_buffer;
  this->m_max_end = m_buffer + 256;
  *m_buffer = 0;
  *m_buffer = 0;
}


void __usercall vostok::fixed_string<4096>::fixed_string<4096>(
        vostok::fixed_string<4096> *this@<esi>,
        const char *src@<edx>)
{
  this->m_max_end = (char *)&this[1];
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  this->m_buffer[0] = 0;
  vostok::buffer_string::operator+=(this, src);
}


void __thiscall vostok::fixed_string<260>::fixed_string<260>(
        vostok::fixed_string<260> *this,
        const vostok::buffer_string *src)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  unsigned int max_count; // [esp+10h] [ebp-Ch] BYREF
  char *begin_src; // [esp+14h] [ebp-8h] BYREF
  char *end_src; // [esp+18h] [ebp-4h] BYREF

  end_src = (char *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end((stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)this);
  begin_src = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                        v2,
                        (int)src);
  max_count = 260;
  vostok::buffer_string::buffer_string(
    this,
    this->m_buffer,
    &max_count,
    (const char *const *)&begin_src,
    (const char *const *)&end_src);
}


void __thiscall vostok::fixed_string<260>::fixed_string<260>(vostok::fixed_string<260> *this, const char *src)
{
  this->m_max_end = (char *)&this[1];
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  this->m_buffer[0] = 0;
  vostok::buffer_string::operator+=(this, src);
}


void __thiscall vostok::fixed_string<260>::fixed_string<260>(vostok::fixed_string<260> *this)
{
  char *m_buffer; // ecx

  m_buffer = this->m_buffer;
  this->m_begin = m_buffer;
  this->m_end = m_buffer;
  this->m_max_end = m_buffer + 260;
  *m_buffer = 0;
  *m_buffer = 0;
}


void __thiscall vostok::fixed_string<20>::fixed_string<20>(vostok::fixed_string<20> *this)
{
  survarium::game_camera *v1; // ecx
  _DWORD *v2; // eax
  unsigned int max_count; // [esp+Ch] [ebp-4h] BYREF

  max_count = 20;
  vostok::buffer_string::buffer_string(this, this->m_buffer, &max_count);
  survarium::weapon_user_dead_state::finalize(v1);
  if ( *v2 )
    this->m_buffer[0] = 0;
}


void __thiscall vostok::fixed_string<24>::fixed_string<24>(
        vostok::fixed_string<24> *this,
        const vostok::fixed_string<24> *src)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  unsigned int max_count; // [esp+10h] [ebp-Ch] BYREF
  char *begin_src; // [esp+14h] [ebp-8h] BYREF
  char *end_src; // [esp+18h] [ebp-4h] BYREF

  end_src = (char *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                      (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)this,
                      (int)src);
  begin_src = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                        v2,
                        (int)src);
  max_count = 24;
  vostok::buffer_string::buffer_string(
    this,
    this->m_buffer,
    &max_count,
    (const char *const *)&begin_src,
    (const char *const *)&end_src);
}


void __usercall vostok::fixed_string<32>::fixed_string<32>(
        vostok::fixed_string<32> *this@<esi>,
        const vostok::buffer_string *src@<eax>)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v3; // ecx
  unsigned int v4; // edi

  m_begin = (unsigned __int8 *)src->m_begin;
  v3 = src->m_end - src->m_begin;
  this->m_max_end = (char *)&this[1];
  v4 = v3;
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  memcpy((unsigned __int8 *)this->m_buffer, m_begin, v3);
  this->m_end += v4;
  *this->m_end = 0;
}


void __usercall vostok::fixed_string<32>::fixed_string<32>(vostok::fixed_string<32> *this@<esi>, const char *src@<edx>)
{
  this->m_max_end = (char *)&this[1];
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  this->m_buffer[0] = 0;
  vostok::buffer_string::operator+=(this, src);
}


void __thiscall vostok::fixed_string<32>::fixed_string<32>(vostok::fixed_string<32> *this)
{
  char *m_buffer; // ecx

  m_buffer = this->m_buffer;
  this->m_begin = m_buffer;
  this->m_end = m_buffer;
  this->m_max_end = m_buffer + 32;
  *m_buffer = 0;
  *m_buffer = 0;
}


void __usercall vostok::fixed_string<512>::fixed_string<512>(
        vostok::fixed_string<512> *this@<esi>,
        const char *src@<edx>)
{
  this->m_max_end = (char *)&this[1];
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  this->m_buffer[0] = 0;
  vostok::buffer_string::operator+=(this, src);
}


void __usercall vostok::fixed_string<512>::fixed_string<512>(vostok::fixed_string<512> *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)a2 = a2 + 12;
  *(_DWORD *)(a2 + 4) = a2 + 12;
  *(_DWORD *)(a2 + 8) = a2 + 524;
  *(_BYTE *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 12) = 0;
}


void __thiscall vostok::fixed_string<42>::fixed_string<42>(vostok::fixed_string<42> *this)
{
  survarium::game_camera *v1; // ecx
  _DWORD *v2; // eax
  unsigned int max_count; // [esp+Ch] [ebp-4h] BYREF

  max_count = 42;
  vostok::buffer_string::buffer_string(this, this->m_buffer, &max_count);
  survarium::weapon_user_dead_state::finalize(v1);
  if ( *v2 )
    this->m_buffer[0] = 0;
}


void __thiscall vostok::fixed_string<46>::fixed_string<46>(
        vostok::fixed_string<46> *this,
        const vostok::fixed_string<46> *src)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  unsigned int max_count; // [esp+10h] [ebp-Ch] BYREF
  char *begin_src; // [esp+14h] [ebp-8h] BYREF
  char *end_src; // [esp+18h] [ebp-4h] BYREF

  end_src = (char *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                      (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)this,
                      (int)src);
  begin_src = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                        v2,
                        (int)src);
  max_count = 46;
  vostok::buffer_string::buffer_string(
    this,
    this->m_buffer,
    &max_count,
    (const char *const *)&begin_src,
    (const char *const *)&end_src);
}


void __thiscall vostok::fixed_string<46>::fixed_string<46>(vostok::fixed_string<46> *this)
{
  survarium::game_camera *v1; // ecx
  _DWORD *v2; // eax
  unsigned int max_count; // [esp+Ch] [ebp-4h] BYREF

  max_count = 46;
  vostok::buffer_string::buffer_string(this, this->m_buffer, &max_count);
  survarium::weapon_user_dead_state::finalize(v1);
  if ( *v2 )
    this->m_buffer[0] = 0;
}


void __thiscall vostok::fixed_string<64>::fixed_string<64>(
        vostok::fixed_string<64> *this,
        const vostok::fixed_string<64> *src)
{
  unsigned __int8 *m_begin; // edx
  unsigned int v4; // ecx
  unsigned int v5; // edi

  m_begin = (unsigned __int8 *)src->m_begin;
  v4 = src->m_end - src->m_begin;
  this->m_max_end = (char *)&this[1];
  v5 = v4;
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  memcpy((unsigned __int8 *)this->m_buffer, m_begin, v4);
  this->m_end += v5;
  *this->m_end = 0;
}


void __thiscall vostok::fixed_string<64>::fixed_string<64>(vostok::fixed_string<64> *this, const char *src)
{
  this->m_max_end = (char *)&this[1];
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  this->m_buffer[0] = 0;
  vostok::buffer_string::operator+=(this, src);
}


void __thiscall vostok::fixed_string<64>::fixed_string<64>(vostok::fixed_string<64> *this)
{
  char *m_buffer; // ecx

  m_buffer = this->m_buffer;
  this->m_begin = m_buffer;
  this->m_end = m_buffer;
  this->m_max_end = m_buffer + 64;
  *m_buffer = 0;
  *m_buffer = 0;
}


void __usercall vostok::fixed_string<128>::fixed_string<128>(
        vostok::fixed_string<128> *this@<esi>,
        const char *src@<edx>)
{
  this->m_max_end = (char *)&this[1];
  this->m_begin = this->m_buffer;
  this->m_end = this->m_buffer;
  this->m_buffer[0] = 0;
  vostok::buffer_string::operator+=(this, src);
}


void __thiscall vostok::fixed_string<2048>::fixed_string<2048>(vostok::fixed_string<2048> *this)
{
  char *m_buffer; // ecx

  m_buffer = this->m_buffer;
  this->m_begin = m_buffer;
  this->m_end = m_buffer;
  this->m_max_end = m_buffer + 2048;
  *m_buffer = 0;
  *m_buffer = 0;
}


void __thiscall vostok::fixed_string<11>::fixed_string<11>(vostok::fixed_string<11> *this)
{
  survarium::game_camera *v1; // ecx
  _DWORD *v2; // eax
  unsigned int max_count; // [esp+Ch] [ebp-4h] BYREF

  max_count = 11;
  vostok::buffer_string::buffer_string(this, this->m_buffer, &max_count);
  survarium::weapon_user_dead_state::finalize(v1);
  if ( *v2 )
    this->m_buffer[0] = 0;
}
