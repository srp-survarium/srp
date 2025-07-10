void __userpurge vostok::animation::bone_names::create_internals_in_place(
        vostok::animation::bone_names *this@<edx>,
        _BYTE *memory@<eax>,
        unsigned int bones_count)
{
  unsigned int v3; // esi
  int v4; // ecx
  char *v5; // eax

  v3 = bones_count;
  this->m_internal_memory_position = memory - (_BYTE *)this;
  this->m_bone_count = bones_count;
  if ( bones_count )
  {
    v4 = 0;
    do
    {
      v5 = (char *)&this[v4] + this->m_internal_memory_position;
      if ( v5 )
      {
        *((_DWORD *)v5 + 16) = -1;
        *((_DWORD *)v5 + 17) = -1;
      }
      v4 += 9;
      --v3;
    }
    while ( v3 );
  }
}
