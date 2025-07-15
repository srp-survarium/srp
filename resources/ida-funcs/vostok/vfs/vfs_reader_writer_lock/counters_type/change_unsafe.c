void __userpurge vostok::vfs::vfs_reader_writer_lock::counters_type::change_unsafe(
        vostok::vfs::vfs_reader_writer_lock::counters_type *this@<eax>,
        vostok::vfs::lock_type_enum lock_type@<ecx>,
        int change)
{
  $E3F6406041541B22B272F6C75322E84C v3; // ecx
  int v4; // edx
  unsigned int v5; // edx
  int v6; // edx
  bool v7; // zf
  $E3F6406041541B22B272F6C75322E84C v8; // edx
  int v9; // edx

  if ( change != -1 )
  {
    if ( lock_type == lock_type_read )
    {
      v3 = this->0;
      v4 = (*(_DWORD *)&this->0 & 0xFFFFC000) + 0x4000;
      goto LABEL_4;
    }
    if ( lock_type == (lock_type_write|lock_type_read) )
    {
      v3 = this->0;
      v6 = *(_DWORD *)&this->0 + 1;
      goto LABEL_7;
    }
    v7 = lock_type == lock_type_write;
    v3 = this->0;
    v8 = this->0;
    if ( v7 )
    {
LABEL_9:
      v5 = (*(_DWORD *)&v3 ^ (((*(unsigned int *)&v8 >> 30) - 1) << 30)) & 0x40000000;
      goto LABEL_18;
    }
    v9 = (int)&s_ui_commands_allocator.m_buffer[(*(_DWORD *)&v8 & 0xFF000000) + 2035360];
LABEL_17:
    v5 = (*(_DWORD *)&v3 ^ v9) & 0x3F000000;
    goto LABEL_18;
  }
  if ( lock_type != lock_type_read )
  {
    if ( lock_type == (lock_type_write|lock_type_read) )
    {
      v3 = this->0;
      v6 = *(_DWORD *)&this->0 - 1;
LABEL_7:
      v5 = (*(_WORD *)&v3 ^ (unsigned __int16)v6) & 0x3FFF;
      goto LABEL_18;
    }
    v7 = lock_type == lock_type_write;
    v3 = this->0;
    v8 = this->0;
    if ( v7 )
      goto LABEL_9;
    v9 = (HIBYTE(*(unsigned int *)&v8) - 1) << 24;
    goto LABEL_17;
  }
  v3 = this->0;
  v4 = ((*(_DWORD *)&this->0 >> 14) - 1) << 14;
LABEL_4:
  v5 = (unsigned int)&s_ui_commands_allocator.m_buffer[2018976] & (*(_DWORD *)&v3 ^ v4);
LABEL_18:
  this->0 = ($E3F6406041541B22B272F6C75322E84C)(*(_DWORD *)&v3 ^ v5);
}
