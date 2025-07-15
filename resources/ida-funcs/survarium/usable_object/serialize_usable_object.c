void __userpurge survarium::usable_object::serialize_usable_object(
        survarium::usable_object *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::buffer_writer *writer,
        unsigned int time_offset)
{
  _DWORD *i; // esi
  int v6; // eax
  vostok::network_core::buffer_writer *v7; // ecx
  unsigned __int8 v8; // [esp+Fh] [ebp-1h] BYREF

  v8 = *(_BYTE *)(a2 + 40);
  vostok::network_core::buffer_writer::w<unsigned char>(
    &v8,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\usable_object.cpp",
    (const char *)0x4A,
    "survarium::usable_object::serialize_usable_object",
    "static_cast< u8 > ( m_usable_object_users.size() )");
  for ( i = *(_DWORD **)(a2 + 48); i; i = (_DWORD *)i[5] )
  {
    v6 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*i + 16))(*i);
    vostok::network_core::buffer_writer::w<unsigned char>(
      (unsigned __int8 *)(v6 + 304),
      v7,
      writer,
      ".\\usable_object.cpp",
      (const char *)0x53,
      "survarium::usable_object::serialize_usable_object",
      "player->id");
  }
}
