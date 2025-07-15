char __userpurge vostok::logging::log_file::process_next_line<void (__cdecl *)(char)>@<al>(
        vostok::logging::log_file *this@<ecx>,
        _DWORD *a2@<eax>,
        void (__cdecl **buffer_size)(char),
        void (__cdecl *const *processor)(char))
{
  unsigned int v5; // ebx
  int v6; // eax
  unsigned int v7; // edi
  vostok::logging::log_file *v9; // ecx
  vostok::logging::log_file *v10; // ecx
  unsigned __int64 v11; // [esp-10h] [ebp-2Ch]
  unsigned __int64 v12; // [esp-8h] [ebp-24h]
  vostok::logging::log_file *v13; // [esp-4h] [ebp-20h]
  vostok::logging::log_file *v14; // [esp-4h] [ebp-20h]
  unsigned __int64 v15; // [esp+Ch] [ebp-10h]
  char next_char; // [esp+18h] [ebp-4h]

  v5 = a2[4368];
  v6 = a2[4372];
  v7 = a2[4369];
  if ( v5 == v6 && v7 == a2[4373] )
    return 0;
  HIDWORD(v12) = (v5 != 0) + v7 - 1;
  LODWORD(v12) = v5 - 1;
  HIDWORD(v11) = a2[4373];
  LODWORD(v11) = v6;
  v15 = vostok::math::min(v11, v12);
  next_char = 0;
  if ( __PAIR64__(v7, v5) < v15 )
  {
    do
    {
      next_char = vostok::logging::log_file::read_next_char(v9, (int)a2);
      (*buffer_size)(next_char);
      v9 = v13;
    }
    while ( next_char != 10 && *((_QWORD *)a2 + 2184) < v15 );
  }
  (*buffer_size)(0);
  v10 = v14;
  if ( next_char != 10 )
  {
    while ( (a2[4368] != a2[4372] || a2[4369] != a2[4373])
         && vostok::logging::log_file::read_next_char(v10, (int)a2) != 10 )
      ;
  }
  return 1;
}


char __usercall vostok::logging::log_file::process_next_line<vostok::logging::processor>@<al>(
        vostok::logging::log_file *this@<eax>,
        const vostok::logging::processor *processor@<edi>)
{
  unsigned __int64 m_current_pos; // rcx
  unsigned int m_file_size; // eax
  vostok::logging::log_file *m_current_pos_high; // ecx
  unsigned __int64 v7; // rax
  vostok::logging::log_file *buffer_ptr; // ecx
  unsigned __int64 v9; // [esp-10h] [ebp-20h]
  unsigned __int64 v10; // [esp+8h] [ebp-8h]

  m_current_pos = this->m_current_pos;
  m_file_size = this->m_file_size;
  if ( m_current_pos == __PAIR64__(HIDWORD(this->m_file_size), m_file_size) )
    return 0;
  HIDWORD(v9) = HIDWORD(this->m_file_size);
  LODWORD(v9) = m_file_size;
  v7 = vostok::math::min(v9, m_current_pos + 511);
  v10 = v7;
  LOBYTE(v7) = 0;
  if ( HIDWORD(m_current_pos) <= HIDWORD(v7) )
  {
    if ( HIDWORD(m_current_pos) < HIDWORD(v7)
      || (m_current_pos_high = (vostok::logging::log_file *)v10, LODWORD(this->m_current_pos) < (unsigned int)v10) )
    {
      while ( 1 )
      {
        LOBYTE(v7) = vostok::logging::log_file::read_next_char(m_current_pos_high, (int)this);
        *processor->buffer_ptr++ = v7;
        if ( (_BYTE)v7 == 10 )
          break;
        m_current_pos_high = (vostok::logging::log_file *)HIDWORD(this->m_current_pos);
        if ( (unsigned int)m_current_pos_high >= HIDWORD(v10) )
        {
          if ( (unsigned int)m_current_pos_high > HIDWORD(v10) )
            break;
          m_current_pos_high = (vostok::logging::log_file *)this->m_current_pos;
          if ( (unsigned int)m_current_pos_high >= (unsigned int)v10 )
            break;
        }
      }
    }
  }
  buffer_ptr = (vostok::logging::log_file *)processor->buffer_ptr;
  *processor->buffer_ptr++ = 0;
  while ( (_BYTE)v7 != 10
       && (LODWORD(this->m_current_pos) != LODWORD(this->m_file_size)
        || HIDWORD(this->m_current_pos) != HIDWORD(this->m_file_size)) )
    LOBYTE(v7) = vostok::logging::log_file::read_next_char(buffer_ptr, (int)this);
  return 1;
}
