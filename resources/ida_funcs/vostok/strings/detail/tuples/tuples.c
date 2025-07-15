void __userpurge vostok::strings::detail::tuples::tuples(
        vostok::strings::detail::tuples *this@<esi>,
        char *p0@<edi>,
        const char *p1,
        const char *p2)
{
  unsigned int v4; // eax
  unsigned int v5; // eax

  `vector constructor iterator'(
    (char *)this,
    8u,
    6,
    (void *(__thiscall *)(void *))vostok::render::lod_render_info::lod_render_info);
  this->m_count = 3;
  if ( p0 )
    v4 = strlen(p0);
  else
    v4 = 0;
  this->m_strings[0].first = p0;
  this->m_strings[0].second = v4;
  if ( p1 )
    v5 = strlen(p1);
  else
    v5 = 0;
  this->m_strings[1].second = v5;
  this->m_strings[1].first = p1;
  this->m_strings[2].second = strlen((const char *)&stru_95AF78.m_key_bindings[32]);
  this->m_strings[2].first = (const char *)&stru_95AF78.m_key_bindings[32];
}


void __usercall vostok::strings::detail::tuples::tuples(vostok::strings::detail::tuples *this@<ecx>, int a2@<esi>)
{
  `vector constructor iterator'(
    (char *)a2,
    8u,
    6,
    (void *(__thiscall *)(void *))vostok::render::lod_render_info::lod_render_info);
  *(_DWORD *)(a2 + 48) = 3;
  *(_DWORD *)(a2 + 4) = strlen("resources/localization/");
  *(_DWORD *)a2 = "resources/localization/";
  *(_DWORD *)(a2 + 12) = strlen(s_localization_str);
  *(_DWORD *)(a2 + 8) = s_localization_str;
  *(_DWORD *)(a2 + 20) = strlen("/localization");
  *(_DWORD *)(a2 + 16) = "/localization";
}


void __userpurge vostok::strings::detail::tuples::tuples(
        vostok::strings::detail::tuples *this@<esi>,
        const char *p0@<edi>,
        const char *p1)
{
  unsigned int v3; // eax

  `vector constructor iterator'(
    (char *)this,
    8u,
    6,
    (void *(__thiscall *)(void *))vostok::render::lod_render_info::lod_render_info);
  this->m_count = 2;
  if ( p0 )
    v3 = strlen(p0);
  else
    v3 = 0;
  this->m_strings[0].first = p0;
  this->m_strings[0].second = v3;
  if ( p1 )
  {
    this->m_strings[1].second = strlen(p1);
    this->m_strings[1].first = p1;
  }
  else
  {
    this->m_strings[1].first = 0;
    this->m_strings[1].second = 0;
  }
}


void __userpurge vostok::strings::detail::tuples::tuples(
        vostok::strings::detail::tuples *this@<esi>,
        const char *p0@<edi>,
        const char *p1,
        char *p2)
{
  unsigned int v4; // eax
  unsigned int v5; // eax

  `vector constructor iterator'(
    (char *)this,
    8u,
    6,
    (void *(__thiscall *)(void *))vostok::render::lod_render_info::lod_render_info);
  this->m_count = 3;
  if ( p0 )
    v4 = strlen(p0);
  else
    v4 = 0;
  this->m_strings[0].first = p0;
  this->m_strings[0].second = v4;
  if ( p1 )
    v5 = strlen(p1);
  else
    v5 = 0;
  this->m_strings[1].first = p1;
  this->m_strings[1].second = v5;
  if ( p2 )
  {
    this->m_strings[2].second = strlen(p2);
    this->m_strings[2].first = p2;
  }
  else
  {
    this->m_strings[2].first = 0;
    this->m_strings[2].second = 0;
  }
}


void __thiscall vostok::strings::detail::tuples::tuples(
        vostok::strings::detail::tuples *this,
        const char *p0,
        const char *p1,
        const char *p2,
        const char *p3,
        const char *p4)
{
  `vector constructor iterator'(
    (char *)this,
    8u,
    6,
    (void *(__thiscall *)(void *))vostok::render::lod_render_info::lod_render_info);
  this->m_count = 5;
  vostok::strings::detail::tuples::helper<0>::add_string<char const *>(this, p0);
  vostok::strings::detail::tuples::helper<1>::add_string<char const *>(this, p1);
  vostok::strings::detail::tuples::helper<2>::add_string<char const *>(this, p2);
  vostok::strings::detail::tuples::helper<3>::add_string<char const *>(this, p3);
  vostok::strings::detail::tuples::helper<4>::add_string<char const *>(this, p4);
}
