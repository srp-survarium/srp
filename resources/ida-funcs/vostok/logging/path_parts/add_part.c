void __userpurge vostok::logging::path_parts::add_part(
        vostok::logging::path_parts *this@<ecx>,
        _DWORD *a2@<eax>,
        char *part)
{
  if ( *a2 == a2[1] )
    a2[7] = part;
  vostok::buffer_vector<char const *>::push_back(&this->m_parts, (int)a2, (const char **)&part);
}
