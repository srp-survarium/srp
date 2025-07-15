void __userpurge survarium::hit_animations_selector::serialize(
        survarium::hit_animations_selector *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::buffer_writer *writer,
        const unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v5; // ecx
  unsigned __int8 *v6; // ebx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  int v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h] BYREF

  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)(a2 + 244),
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\hit_animations_selector.cpp",
    (const char *)0x90,
    "survarium::hit_animations_selector::serialize",
    "m_need_to_select_animations");
  v6 = (unsigned __int8 *)(a2 + 12);
  v9 = 8;
  do
  {
    v10 = time_offset + *((_DWORD *)v6 - 1);
    vostok::network_core::buffer_writer::w<unsigned int>(
      (unsigned __int8 *)&v10,
      v5,
      writer,
      ".\\hit_animation_selector_body_part.cpp",
      (const char *)0x53,
      "survarium::hit_animations_selector::hit_body_part::serialize",
      "last_hit_time + time_offset");
    vostok::network_core::buffer_writer::w<unsigned int>(
      v6,
      v7,
      writer,
      ".\\hit_animation_selector_body_part.cpp",
      (const char *)0x54,
      "survarium::hit_animations_selector::hit_body_part::serialize",
      "current_hit_amount");
    vostok::network_core::buffer_writer::w<unsigned int>(
      v6 + 4,
      v8,
      writer,
      ".\\hit_animation_selector_body_part.cpp",
      (const char *)0x55,
      "survarium::hit_animations_selector::hit_body_part::serialize",
      "target_hit_amount");
    v6 += 24;
    --v9;
  }
  while ( v9 );
}
