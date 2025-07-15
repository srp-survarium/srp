vostok::particle::particle_action *__cdecl vostok::particle::create_action_by_index(
        vostok::particle::particle_system_lod *lod,
        vostok::mutable_buffer *buffer,
        vostok::particle::particle_emitter *emitter,
        stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *index)
{
  const vostok::variant<32> **v4; // eax
  const vostok::variant<32> **v5; // eax
  const vostok::variant<32> **v6; // eax
  const vostok::variant<32> **v7; // eax
  const vostok::variant<32> **v8; // eax
  const vostok::variant<32> **v9; // eax
  const vostok::variant<32> **v10; // eax
  const vostok::variant<32> **v11; // eax
  const vostok::variant<32> **v12; // eax
  const vostok::variant<32> **v13; // eax
  const vostok::variant<32> **v14; // eax
  const vostok::variant<32> **v15; // eax
  const vostok::variant<32> **v16; // eax
  const vostok::variant<32> **v17; // eax
  const vostok::variant<32> **v18; // eax
  const vostok::variant<32> **v19; // eax
  const vostok::variant<32> **v20; // eax
  const vostok::variant<32> **v21; // eax
  const vostok::variant<32> **v22; // eax
  const vostok::variant<32> **v23; // eax
  const vostok::variant<32> **v24; // eax
  const vostok::variant<32> **v25; // eax
  const vostok::variant<32> **v26; // eax
  vostok::particle::particle_action *v27; // eax
  const vostok::variant<32> **v28; // eax
  vostok::particle::particle_action *v29; // eax
  const vostok::variant<32> **v30; // eax
  vostok::particle::particle_action *v31; // eax
  const vostok::variant<32> **v32; // eax
  vostok::particle::particle_action *v33; // eax
  vostok::particle::particle_action *v35; // [esp+0h] [ebp-F8h]
  vostok::particle::particle_action *v36; // [esp+4h] [ebp-F4h]
  vostok::particle::particle_action *v37; // [esp+8h] [ebp-F0h]
  vostok::particle::particle_action *v38; // [esp+Ch] [ebp-ECh]
  vostok::particle::particle_modifier *v39; // [esp+10h] [ebp-E8h]
  vostok::particle::particle_action_random_velocity *v40; // [esp+14h] [ebp-E4h]
  vostok::particle::particle_event *v41; // [esp+18h] [ebp-E0h]
  vostok::particle::particle_event *v42; // [esp+1Ch] [ebp-DCh]
  vostok::particle::particle_event *v43; // [esp+20h] [ebp-D8h]
  vostok::particle::particle_event *v44; // [esp+24h] [ebp-D4h]
  vostok::particle::particle_action_data_type *v45; // [esp+28h] [ebp-D0h]
  vostok::particle::particle_action_data_type *v46; // [esp+2Ch] [ebp-CCh]
  vostok::particle::particle_action_data_type *v47; // [esp+30h] [ebp-C8h]
  vostok::particle::particle_action_data_type *v48; // [esp+34h] [ebp-C4h]
  vostok::particle::particle_action_data_type *v49; // [esp+38h] [ebp-C0h]
  vostok::particle::particle_action_source *v50; // [esp+3Ch] [ebp-BCh]
  vostok::particle::particle_modifier *v51; // [esp+40h] [ebp-B8h]
  vostok::particle::particle_modifier *v52; // [esp+44h] [ebp-B4h]
  vostok::particle::particle_modifier *v53; // [esp+48h] [ebp-B0h]
  vostok::particle::particle_modifier *v54; // [esp+4Ch] [ebp-ACh]
  vostok::particle::particle_modifier *v55; // [esp+50h] [ebp-A8h]
  vostok::particle::particle_modifier *v56; // [esp+54h] [ebp-A4h]
  vostok::particle::particle_modifier *v57; // [esp+58h] [ebp-A0h]
  vostok::particle::particle_modifier *v58; // [esp+5Ch] [ebp-9Ch]
  vostok::particle::particle_modifier *v59; // [esp+60h] [ebp-98h]
  vostok::particle::particle_modifier *v60; // [esp+64h] [ebp-94h]
  vostok::particle::particle_action_gravity *v61; // [esp+8Ch] [ebp-6Ch]
  vostok::particle::particle_action_kill_volume *v62; // [esp+90h] [ebp-68h]
  vostok::particle::particle_action_acceleration *v63; // [esp+94h] [ebp-64h]
  vostok::particle::particle_action_orbit *v64; // [esp+98h] [ebp-60h]
  vostok::particle::particle_modifier *v65; // [esp+9Ch] [ebp-5Ch]
  vostok::particle::particle_modifier *v66; // [esp+A0h] [ebp-58h]
  vostok::particle::particle_event *v67; // [esp+A4h] [ebp-54h]
  vostok::particle::particle_event *v68; // [esp+A8h] [ebp-50h]
  vostok::particle::particle_event *v69; // [esp+ACh] [ebp-4Ch]
  vostok::particle::particle_event *v70; // [esp+B0h] [ebp-48h]
  vostok::particle::particle_action_data_type *v71; // [esp+B4h] [ebp-44h]
  vostok::particle::particle_action_data_type *v72; // [esp+B8h] [ebp-40h]
  vostok::particle::particle_action_data_type *v73; // [esp+BCh] [ebp-3Ch]
  vostok::particle::particle_action_data_type *v74; // [esp+C0h] [ebp-38h]
  vostok::particle::particle_action_data_type *v75; // [esp+C4h] [ebp-34h]
  vostok::particle::particle_modifier *v76; // [esp+C8h] [ebp-30h]
  vostok::particle::particle_modifier *v77; // [esp+CCh] [ebp-2Ch]
  vostok::particle::particle_modifier *v78; // [esp+D0h] [ebp-28h]
  vostok::particle::particle_modifier *v79; // [esp+D4h] [ebp-24h]
  vostok::particle::particle_modifier *v80; // [esp+D8h] [ebp-20h]
  vostok::particle::particle_modifier *v81; // [esp+DCh] [ebp-1Ch]
  vostok::particle::particle_modifier *v82; // [esp+E0h] [ebp-18h]
  vostok::particle::particle_modifier *v83; // [esp+E4h] [ebp-14h]
  vostok::particle::particle_modifier *v84; // [esp+E8h] [ebp-10h]
  vostok::particle::particle_modifier *v85; // [esp+ECh] [ebp-Ch]
  vostok::particle::particle_modifier *v86; // [esp+F0h] [ebp-8h]
  vostok::particle::particle_action *action; // [esp+F4h] [ebp-4h]

  action = 0;
  switch ( (unsigned int)index )
  {
    case 0u:
      v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v86 = (vostok::particle::particle_modifier *)operator new(0x58u, v4);
      if ( v86 )
      {
        vostok::particle::particle_modifier::particle_modifier(v86);
        v86->__vftable = (vostok::particle::particle_modifier_vtbl *)&vostok::particle::particle_action_initial_color::`vftable';
        vostok::particle::curve_line_color::curve_line_color((vostok::particle::curve_line_color *)&v86[1]);
        v60 = v86;
      }
      else
      {
        v60 = 0;
      }
      action = v60;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x58, buffer);
      break;
    case 1u:
      v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v85 = (vostok::particle::particle_modifier *)operator new(0xE0u, v5);
      if ( v85 )
      {
        vostok::particle::particle_modifier::particle_modifier(v85);
        v85->__vftable = (vostok::particle::particle_modifier_vtbl *)&vostok::particle::particle_action_initial_size::`vftable';
        vostok::particle::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float((vostok::particle::curve_line_ranged_xyz_float *)&v85[1]);
        v59 = v85;
      }
      else
      {
        v59 = 0;
      }
      action = v59;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0xE0, buffer);
      break;
    case 2u:
      v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v84 = (vostok::particle::particle_modifier *)operator new(0xE0u, v6);
      if ( v84 )
      {
        vostok::particle::particle_modifier::particle_modifier(v84);
        v84->__vftable = (vostok::particle::particle_modifier_vtbl *)&vostok::particle::particle_action_initial_velocity::`vftable';
        vostok::particle::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float((vostok::particle::curve_line_ranged_xyz_float *)&v84[1]);
        v58 = v84;
      }
      else
      {
        v58 = 0;
      }
      action = v58;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0xE0, buffer);
      break;
    case 3u:
      v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v83 = (vostok::particle::particle_modifier *)operator new(0xE0u, v7);
      if ( v83 )
      {
        vostok::particle::particle_modifier::particle_modifier(v83);
        v83->__vftable = (vostok::particle::particle_modifier_vtbl *)&vostok::particle::particle_action_initial_rotation::`vftable';
        vostok::particle::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float((vostok::particle::curve_line_ranged_xyz_float *)&v83[1]);
        v57 = v83;
      }
      else
      {
        v57 = 0;
      }
      action = v57;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0xE0, buffer);
      break;
    case 4u:
      v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v82 = (vostok::particle::particle_modifier *)operator new(0xE0u, v8);
      if ( v82 )
      {
        vostok::particle::particle_modifier::particle_modifier(v82);
        v82->__vftable = (vostok::particle::particle_modifier_vtbl *)&vostok::particle::particle_action_velocity_over_lifetime::`vftable';
        vostok::particle::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float((vostok::particle::curve_line_ranged_xyz_float *)&v82[1]);
        v56 = v82;
      }
      else
      {
        v56 = 0;
      }
      action = v56;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0xE0, buffer);
      break;
    case 5u:
      v9 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v81 = (vostok::particle::particle_modifier *)operator new(0x30u, v9);
      if ( v81 )
      {
        vostok::particle::particle_modifier::particle_modifier(v81);
        v81->__vftable = (vostok::particle::particle_modifier_vtbl *)&vostok::particle::particle_action_color_over_lifetime::`vftable';
        v81[1].__vftable = 0;
        *((_DWORD *)&v81[1].__vftable + 1) = 0;
        v55 = v81;
      }
      else
      {
        v55 = 0;
      }
      action = v55;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x30, buffer);
      break;
    case 6u:
      v10 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v80 = (vostok::particle::particle_modifier *)operator new(0xE0u, v10);
      if ( v80 )
      {
        vostok::particle::particle_modifier::particle_modifier(v80);
        v80->__vftable = (vostok::particle::particle_modifier_vtbl *)&vostok::particle::particle_action_rotation_over_lifetime::`vftable';
        vostok::particle::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float((vostok::particle::curve_line_ranged_xyz_float *)&v80[1]);
        v54 = v80;
      }
      else
      {
        v54 = 0;
      }
      action = v54;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0xE0, buffer);
      break;
    case 7u:
      v11 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v79 = (vostok::particle::particle_modifier *)operator new(0xE8u, v11);
      if ( v79 )
      {
        vostok::particle::particle_modifier::particle_modifier(v79);
        v79->__vftable = (vostok::particle::particle_modifier_vtbl *)&vostok::particle::particle_action_rotation_over_velocity::`vftable';
        vostok::particle::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float((vostok::particle::curve_line_ranged_xyz_float *)&v79[1]);
        v53 = v79;
      }
      else
      {
        v53 = 0;
      }
      action = v53;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0xE8, buffer);
      break;
    case 8u:
      v12 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v78 = (vostok::particle::particle_modifier *)operator new(0xE8u, v12);
      if ( v78 )
      {
        vostok::particle::particle_modifier::particle_modifier(v78);
        v78->__vftable = (vostok::particle::particle_modifier_vtbl *)&vostok::particle::particle_action_size_over_lifetime::`vftable';
        vostok::particle::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float((vostok::particle::curve_line_ranged_xyz_float *)&v78[1]);
        v52 = v78;
      }
      else
      {
        v52 = 0;
      }
      action = v52;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0xE8, buffer);
      break;
    case 9u:
      v13 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v77 = (vostok::particle::particle_modifier *)operator new(0xE0u, v13);
      if ( v77 )
      {
        vostok::particle::particle_modifier::particle_modifier(v77);
        v77->__vftable = (vostok::particle::particle_modifier_vtbl *)&vostok::particle::particle_action_size_over_velocity::`vftable';
        vostok::particle::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float((vostok::particle::curve_line_ranged_xyz_float *)&v77[1]);
        v51 = v77;
      }
      else
      {
        v51 = 0;
      }
      action = v51;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0xE0, buffer);
      break;
    case 0xBu:
      v14 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v76 = (vostok::particle::particle_modifier *)operator new(0x100u, v14);
      if ( v76 )
      {
        vostok::particle::particle_modifier::particle_modifier(v76);
        v76->__vftable = (vostok::particle::particle_modifier_vtbl *)&vostok::particle::particle_action_source::`vftable';
        vostok::particle::particle_domain_complex::particle_domain_complex((vostok::particle::particle_domain_complex *)&v76[1]);
        v50 = (vostok::particle::particle_action_source *)v76;
      }
      else
      {
        v50 = 0;
      }
      action = v50;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x100, buffer);
      vostok::particle::particle_emitter::set_source_action(emitter, v50);
      break;
    case 0xCu:
      v15 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v75 = (vostok::particle::particle_action_data_type *)operator new(0x90u, v15);
      if ( v75 )
      {
        vostok::particle::particle_action_data_type::particle_action_data_type(v75);
        v75->__vftable = (vostok::particle::particle_action_data_type_vtbl *)&vostok::particle::particle_action_billboard::`vftable';
        vostok::particle::curve_line_ranged_float::curve_line_ranged_float((vostok::particle::curve_line_ranged_float *)&v75[1]);
        v49 = v75;
      }
      else
      {
        v49 = 0;
      }
      action = v49;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x90, buffer);
      vostok::particle::particle_emitter::set_data_type_action(emitter, v49);
      break;
    case 0xDu:
      v16 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v74 = (vostok::particle::particle_action_data_type *)operator new(0x18u, v16);
      if ( v74 )
      {
        vostok::particle::particle_action_data_type::particle_action_data_type(v74);
        v74->__vftable = (vostok::particle::particle_action_data_type_vtbl *)&vostok::particle::particle_action_mesh::`vftable';
        v48 = v74;
      }
      else
      {
        v48 = 0;
      }
      action = v48;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x18, buffer);
      vostok::particle::particle_emitter::set_data_type_action(emitter, v48);
      break;
    case 0xEu:
      v17 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v73 = (vostok::particle::particle_action_data_type *)operator new(0x28u, v17);
      if ( v73 )
      {
        vostok::particle::particle_action_data_type::particle_action_data_type(v73);
        v73->__vftable = (vostok::particle::particle_action_data_type_vtbl *)&vostok::particle::particle_action_trail::`vftable';
        v47 = v73;
      }
      else
      {
        v47 = 0;
      }
      action = v47;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x28, buffer);
      vostok::particle::particle_emitter::set_data_type_action(emitter, v47);
      break;
    case 0xFu:
      v18 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v72 = (vostok::particle::particle_action_data_type *)operator new(0x30u, v18);
      if ( v72 )
      {
        vostok::particle::particle_action_data_type::particle_action_data_type(v72);
        v72->__vftable = (vostok::particle::particle_action_data_type_vtbl *)&vostok::particle::particle_action_beam::`vftable';
        v46 = v72;
      }
      else
      {
        v46 = 0;
      }
      action = v46;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x30, buffer);
      vostok::particle::particle_emitter::set_data_type_action(emitter, v46);
      break;
    case 0x10u:
      v19 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v71 = (vostok::particle::particle_action_data_type *)operator new(0x18u, v19);
      if ( v71 )
      {
        vostok::particle::particle_action_data_type::particle_action_data_type(v71);
        v71->__vftable = (vostok::particle::particle_action_data_type_vtbl *)&vostok::particle::particle_action_decal::`vftable';
        v45 = v71;
      }
      else
      {
        v45 = 0;
      }
      action = v45;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x18, buffer);
      vostok::particle::particle_emitter::set_data_type_action(emitter, v45);
      break;
    case 0x11u:
      v20 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v70 = (vostok::particle::particle_event *)operator new(0x20u, v20);
      if ( v70 )
      {
        vostok::particle::particle_event::particle_event(v70);
        v70->__vftable = (vostok::particle::particle_event_vtbl *)&vostok::particle::particle_event_on_play::`vftable';
        v44 = v70;
      }
      else
      {
        v44 = 0;
      }
      action = v44;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x20, buffer);
      break;
    case 0x12u:
      v21 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v69 = (vostok::particle::particle_event *)operator new(0x20u, v21);
      if ( v69 )
      {
        vostok::particle::particle_event::particle_event(v69);
        v69->__vftable = (vostok::particle::particle_event_vtbl *)&vostok::particle::particle_event_on_birth::`vftable';
        v43 = v69;
      }
      else
      {
        v43 = 0;
      }
      action = v43;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x20, buffer);
      break;
    case 0x13u:
      v22 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v68 = (vostok::particle::particle_event *)operator new(0x20u, v22);
      if ( v68 )
      {
        vostok::particle::particle_event::particle_event(v68);
        v68->__vftable = (vostok::particle::particle_event_vtbl *)&vostok::particle::particle_event_on_death::`vftable';
        v42 = v68;
      }
      else
      {
        v42 = 0;
      }
      action = v42;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x20, buffer);
      break;
    case 0x14u:
      v23 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v67 = (vostok::particle::particle_event *)operator new(0x20u, v23);
      if ( v67 )
      {
        vostok::particle::particle_event::particle_event(v67);
        v67->__vftable = (vostok::particle::particle_event_vtbl *)&vostok::particle::particle_event_on_collide::`vftable';
        v41 = v67;
      }
      else
      {
        v41 = 0;
      }
      action = v41;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x20, buffer);
      break;
    case 0x15u:
      v24 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v66 = (vostok::particle::particle_modifier *)operator new(0x108u, v24);
      if ( v66 )
      {
        vostok::particle::particle_modifier::particle_modifier(v66);
        v66->__vftable = (vostok::particle::particle_modifier_vtbl *)&vostok::particle::particle_action_random_velocity::`vftable';
        vostok::particle::particle_domain_complex::particle_domain_complex((vostok::particle::particle_domain_complex *)&v66[1]);
        v40 = (vostok::particle::particle_action_random_velocity *)v66;
      }
      else
      {
        v40 = 0;
      }
      action = v40;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x108, buffer);
      vostok::particle::particle_emitter::set_target_action(emitter, v40);
      break;
    case 0x16u:
      v25 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v65 = (vostok::particle::particle_modifier *)operator new(0xE0u, v25);
      if ( v65 )
      {
        vostok::particle::particle_modifier::particle_modifier(v65);
        v65->__vftable = (vostok::particle::particle_modifier_vtbl *)&vostok::particle::particle_action_initial_rotation_rate::`vftable';
        vostok::particle::curve_line_ranged_xyz_float::curve_line_ranged_xyz_float((vostok::particle::curve_line_ranged_xyz_float *)&v65[1]);
        v39 = v65;
      }
      else
      {
        v39 = 0;
      }
      action = v39;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0xE0, buffer);
      break;
    case 0x17u:
      v26 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v64 = (vostok::particle::particle_action_orbit *)operator new(0x270u, v26);
      if ( v64 )
      {
        vostok::particle::particle_action_orbit::particle_action_orbit(v64);
        v38 = v27;
      }
      else
      {
        v38 = 0;
      }
      action = v38;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x270, buffer);
      break;
    case 0x18u:
      v28 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v63 = (vostok::particle::particle_action_acceleration *)operator new(0xE0u, v28);
      if ( v63 )
      {
        vostok::particle::particle_action_acceleration::particle_action_acceleration(v63);
        v37 = v29;
      }
      else
      {
        v37 = 0;
      }
      action = v37;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0xE0, buffer);
      break;
    case 0x19u:
      v30 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v62 = (vostok::particle::particle_action_kill_volume *)operator new(0x108u, v30);
      if ( v62 )
      {
        vostok::particle::particle_action_kill_volume::particle_action_kill_volume(v62);
        v36 = v31;
      }
      else
      {
        v36 = 0;
      }
      action = v36;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x108, buffer);
      break;
    case 0x1Au:
      v32 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(index, (int)buffer);
      v61 = (vostok::particle::particle_action_gravity *)operator new(0x20u, v32);
      if ( v61 )
      {
        vostok::particle::particle_action_gravity::particle_action_gravity(v61);
        v35 = v33;
      }
      else
      {
        v35 = 0;
      }
      action = v35;
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x20, buffer);
      break;
    default:
      return action;
  }
  return action;
}
