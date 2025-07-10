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
