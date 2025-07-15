void __userpurge vostok::strings::detail::tuples::tuples(
        vostok::strings::detail::tuples *this@<ecx>,
        vostok::strings::detail::tuples *a2@<eax>,
        const char *p0)
{
  vostok::strings::detail::tuples *v3; // edi
  int i; // ecx

  v3 = a2;
  for ( i = 5; i >= 0; --i )
  {
    a2->m_strings[0].first = 0;
    a2->m_strings[0].second = 0;
    a2 = (vostok::strings::detail::tuples *)((char *)a2 + 8);
  }
  v3->m_count = 1;
  vostok::strings::detail::tuples::helper<0>::add_string<char const *>(v3, p0);
}


void __userpurge vostok::strings::detail::tuples::tuples(
        vostok::strings::detail::tuples *this@<ecx>,
        vostok::strings::detail::tuples *a2@<eax>,
        const char *p0,
        char *p1,
        const char *p2)
{
  vostok::strings::detail::tuples *v5; // edi
  int i; // ecx
  unsigned int v7; // eax

  v5 = a2;
  for ( i = 5; i >= 0; --i )
  {
    a2->m_strings[0].first = 0;
    a2->m_strings[0].second = 0;
    a2 = (vostok::strings::detail::tuples *)((char *)a2 + 8);
  }
  v5->m_count = 3;
  vostok::strings::detail::tuples::helper<0>::add_string<char const *>(v5, "resources/localization/");
  if ( p0 )
    v7 = strlen(p0);
  else
    v7 = 0;
  v5->m_strings[1].first = p0;
  v5->m_strings[1].second = v7;
  vostok::strings::detail::tuples::helper<2>::add_string<char const *>(v5, p1);
}


void __userpurge vostok::strings::detail::tuples::tuples(
        vostok::strings::detail::tuples *this@<ecx>,
        vostok::strings::detail::tuples *a2@<eax>,
        char *p0,
        char *p1)
{
  vostok::strings::detail::tuples *v4; // edi
  int i; // ecx

  v4 = a2;
  for ( i = 5; i >= 0; --i )
  {
    a2->m_strings[0].first = 0;
    a2->m_strings[0].second = 0;
    a2 = (vostok::strings::detail::tuples *)((char *)a2 + 8);
  }
  v4->m_count = 2;
  vostok::strings::detail::tuples::helper<0>::add_string<char const *>(v4, p0);
  vostok::strings::detail::tuples::helper<1>::add_string<char const *>(v4, p1);
}


void __userpurge vostok::strings::detail::tuples::tuples(
        vostok::strings::detail::tuples *this@<ecx>,
        vostok::strings::detail::tuples *a2@<eax>,
        const char *p0,
        const char *p1,
        char *p2)
{
  vostok::strings::detail::tuples *v5; // edi
  int i; // ecx
  unsigned int v7; // eax

  v5 = a2;
  for ( i = 5; i >= 0; --i )
  {
    a2->m_strings[0].first = 0;
    a2->m_strings[0].second = 0;
    a2 = (vostok::strings::detail::tuples *)((char *)a2 + 8);
  }
  v5->m_count = 3;
  vostok::strings::detail::tuples::helper<0>::add_string<char const *>(v5, p0);
  vostok::strings::detail::tuples::helper<1>::add_string<char const *>(v5, p1);
  if ( p2 )
    v7 = strlen(p2);
  else
    v7 = 0;
  v5->m_strings[2].second = v7;
  v5->m_strings[2].first = p2;
}


void __userpurge vostok::strings::detail::tuples::tuples(
        vostok::strings::detail::tuples *this@<ecx>,
        vostok::strings::detail::tuples *a2@<eax>,
        const char *p0,
        const char *p1,
        char *p2)
{
  vostok::strings::detail::tuples *v5; // edi
  int i; // ecx

  v5 = a2;
  for ( i = 5; i >= 0; --i )
  {
    a2->m_strings[0].first = 0;
    a2->m_strings[0].second = 0;
    a2 = (vostok::strings::detail::tuples *)((char *)a2 + 8);
  }
  v5->m_count = 3;
  vostok::strings::detail::tuples::helper<0>::add_string<char const *>(v5, p0);
  vostok::strings::detail::tuples::helper<1>::add_string<char const *>(v5, p1);
  vostok::strings::detail::tuples::helper<2>::add_string<char const *>(v5, p2);
}


void __userpurge vostok::strings::detail::tuples::tuples(
        vostok::strings::detail::tuples *this@<ecx>,
        vostok::strings::detail::tuples *a2@<eax>,
        const char *p0,
        const char *p1,
        const char *p2,
        const char *p3,
        const char *p4)
{
  vostok::strings::detail::tuples *v7; // edi
  int i; // edx
  unsigned int v9; // eax
  unsigned int v10; // eax

  v7 = a2;
  for ( i = 5; i >= 0; --i )
  {
    a2->m_strings[0].first = 0;
    a2->m_strings[0].second = 0;
    a2 = (vostok::strings::detail::tuples *)((char *)a2 + 8);
  }
  v7->m_count = 5;
  vostok::strings::detail::tuples::helper<0>::add_string<char const *>(v7, p0);
  vostok::strings::detail::tuples::helper<1>::add_string<char const *>(v7, p1);
  vostok::strings::detail::tuples::helper<2>::add_string<char const *>(v7, p2);
  if ( p3 )
    v9 = strlen(p3);
  else
    v9 = 0;
  v7->m_strings[3].first = p3;
  v7->m_strings[3].second = v9;
  if ( p4 )
    v10 = strlen(p4);
  else
    v10 = 0;
  v7->m_strings[4].second = v10;
  v7->m_strings[4].first = p4;
}
