void __userpurge vostok::animation::bone_names::create_internals_in_place(
        unsigned int bones_count@<edx>,
        _BYTE *memory@<eax>,
        vostok::animation::bone_names *this)
{
  int v3; // esi
  char *v4; // eax

  this->m_internal_memory_position = memory - (_BYTE *)this;
  this->m_bone_count = bones_count;
  if ( bones_count )
  {
    v3 = 0;
    do
    {
      v4 = (char *)&this[v3] + this->m_internal_memory_position;
      if ( v4 )
      {
        *((_DWORD *)v4 + 16) = -1;
        *((_DWORD *)v4 + 17) = -1;
      }
      v3 += 9;
      --bones_count;
    }
    while ( bones_count );
  }
}
