void __thiscall survarium::weapon_core::serialize(
        survarium::weapon_core *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer,
        unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::buffer_writer *v10; // ecx
  vostok::network_core::buffer_writer *v11; // ecx
  vostok::network_core::buffer_writer *v12; // ecx
  survarium::dispersion_calculator *v13; // ecx
  vostok::network_core::buffer_writer *v14; // ecx
  survarium::transition_helper *v15; // ecx
  survarium::breath_vibration_calculator *v16; // ecx
  vostok::network_core::buffer_writer *v17; // ecx
  vostok::ai::fsm *v18; // ecx
  const char *v19; // [esp+0h] [ebp-10h]
  unsigned int v20; // [esp+0h] [ebp-10h]
  int v21; // [esp+4h] [ebp-Ch]
  const char *v22; // [esp+8h] [ebp-8h]
  const char *v23; // [esp+Ch] [ebp-4h]

  survarium::inventory_item::serialize(&this->survarium::inventory_item, writer, client_writer, time_offset);
  vostok::network_core::buffer_writer::w<boost::random::linear_congruential_engine<unsigned int,48271,0,2147483647>>(
    &this->m_random_generator,
    v5,
    writer,
    v19,
    v21,
    v22,
    v23);
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&this->m_last_tick_time_in_ms,
    v6,
    writer,
    ".\\weapon_core.cpp",
    (const char *)0x445,
    "survarium::weapon_core::serialize",
    "m_last_tick_time_in_ms");
  vostok::network_core::buffer_writer::w<bool>(
    &this->m_load_ammo_on_next_activate,
    v7,
    writer,
    ".\\weapon_core.cpp",
    (const char *)0x446,
    "survarium::weapon_core::serialize",
    "m_load_ammo_on_next_activate");
  vostok::network_core::buffer_writer::w<unsigned short>(
    (unsigned __int8 *)&this->m_ammo_in_magazine,
    v8,
    writer,
    ".\\weapon_core.cpp",
    (const char *)0x447,
    "survarium::weapon_core::serialize",
    "m_ammo_in_magazine");
  vostok::network_core::buffer_writer::w<unsigned short>(
    (unsigned __int8 *)&this->m_bullets_in_queue,
    v9,
    writer,
    ".\\weapon_core.cpp",
    (const char *)0x448,
    "survarium::weapon_core::serialize",
    "m_bullets_in_queue");
  vostok::network_core::buffer_writer::w<unsigned char>(
    &this->m_fire_queue_type,
    v10,
    writer,
    ".\\weapon_core.cpp",
    (const char *)0x449,
    "survarium::weapon_core::serialize",
    "m_fire_queue_type");
  vostok::network_core::buffer_writer::w<unsigned char>(
    &this->m_selected_ammo_id,
    v11,
    writer,
    ".\\weapon_core.cpp",
    (const char *)0x44A,
    "survarium::weapon_core::serialize",
    "m_selected_ammo_id");
  if ( this->m_is_there_chamber_a_round_state )
    vostok::network_core::buffer_writer::w<bool>(
      &this->m_is_round_chambered,
      v12,
      writer,
      ".\\weapon_core.cpp",
      (const char *)0x44D,
      "survarium::weapon_core::serialize",
      "m_is_round_chambered");
  if ( this->m_user )
  {
    survarium::recoil_calculator::serialize(
      (survarium::recoil_calculator *)v12,
      (const vostok::network_core::buffer_writer *)&this->m_recoil_calculator,
      writer,
      time_offset);
    survarium::dispersion_calculator::serialize(v13, (int)&this->m_dispersion_calculator, writer, time_offset);
    vostok::network_core::buffer_writer::w<bool>(
      &this->m_aimed,
      v14,
      writer,
      ".\\weapon_core.cpp",
      (const char *)0x454,
      "survarium::weapon_core::serialize",
      "m_aimed");
    survarium::transition_helper::serialize(v15, (int)&this->m_aim_progress, writer, time_offset);
    if ( this->m_aimed )
      survarium::breath_vibration_calculator::serialize(
        v16,
        (int)&this->m_breath_vibration_calculator,
        writer,
        client_writer,
        v20);
    vostok::network_core::buffer_writer::w<bool>(
      &this->m_is_in_sprint_transition,
      (vostok::network_core::buffer_writer *)v16,
      writer,
      ".\\weapon_core.cpp",
      (const char *)0x459,
      "survarium::weapon_core::serialize",
      "m_is_in_sprint_transition");
    vostok::network_core::buffer_writer::w<bool>(
      &this->m_need_to_auto_reload,
      v17,
      writer,
      ".\\weapon_core.cpp",
      (const char *)0x45A,
      "survarium::weapon_core::serialize",
      "m_need_to_auto_reload");
    vostok::ai::fsm::serialize(v18, (int)this->m_logic, writer, client_writer);
    this->m_portable_interactive_object->serialize(
      this->m_portable_interactive_object,
      writer,
      client_writer,
      time_offset);
  }
}


void __thiscall survarium::weapon_core::serialize(
        char *this,
        vostok::network_core::buffer_writer *a2,
        const vostok::network_core::buffer_writer *a3,
        unsigned int a4)
{
  survarium::weapon_core::serialize((survarium::weapon_core *)(this - 16), a2, a3, a4);
}
