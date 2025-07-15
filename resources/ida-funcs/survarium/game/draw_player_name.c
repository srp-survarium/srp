void __thiscall survarium::game::draw_player_name(
        survarium::game *this,
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a3)
{
  float v3; // edi
  const char *v4; // ebx
  Scaleform::GFx::DrawTextManager *v5; // ecx
  Scaleform::Render::TreeText **v6; // eax
  char *v7; // ebx
  survarium::flash_text *v8; // ecx
  int v9; // ecx
  vostok::fixed_vector<float,13>::allign_helper v10; // eax
  unsigned int v11; // edi
  int v12; // ecx
  int v13; // eax
  float *v14; // eax
  float *v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  int v18; // ecx
  float v19; // [esp+1Ch] [ebp-50h]
  float v20; // [esp+1Ch] [ebp-50h]
  Scaleform::Render::Size<float> result; // [esp+20h] [ebp-4Ch] BYREF
  int v22; // [esp+28h] [ebp-44h]
  Scaleform::Render::Rect<float> viewRect; // [esp+2Ch] [ebp-40h] BYREF
  _BYTE v24[16]; // [esp+3Ch] [ebp-30h] BYREF
  _BYTE v25[16]; // [esp+4Ch] [ebp-20h] BYREF
  _BYTE v26[16]; // [esp+5Ch] [ebp-10h] BYREF

  survarium::game::hide_player_name(this, (int)player.m_object);
  v3 = *(float *)&player.m_object->m_speed_parameters.m_multipliers.m_buffer[2];
  v4 = (char *)&loc_1143B + (unsigned int)a3.m_object + 1;
  Scaleform::GFx::DrawTextManager::GetTextExtent(
    *(Scaleform::GFx::DrawTextManager **)LODWORD(v3),
    &result,
    (char *)&loc_1143B + (unsigned int)a3.m_object + 1,
    0.0,
    0);
  v5 = *(Scaleform::GFx::DrawTextManager **)LODWORD(v3);
  result.Width = result.Width + 5.0;
  *(Scaleform::Render::Size<float> *)&viewRect.x2 = result;
  viewRect.x1 = 0.0;
  viewRect.y1 = 0.0;
  v6 = Scaleform::GFx::DrawTextManager::CreateText(v5, v4, &viewRect, 0, 0xFFFFFFFF);
  *(_BYTE *)(LODWORD(v3) + 4) = 1;
  v7 = &player.m_object->m_animation_player.m_tree_buffers[0][14296];
  LODWORD(result.Width) = v6;
  result.Height = v3;
  LOBYTE(v22) = 1;
  *(_DWORD *)&player.m_object->m_animation_player.m_tree_buffers[0][14296] = v6;
  *(float *)&player.m_object->m_animation_player.m_tree_buffers[0][14300] = result.Height;
  *(_DWORD *)&player.m_object->m_animation_player.m_tree_buffers[0][14304] = v22;
  (*(void (__thiscall **)(_DWORD, int, _DWORD, int))(**(_DWORD **)v7 + 36))(*(_DWORD *)v7, -65536, 0, -1);
  *(_BYTE *)(*((_DWORD *)v7 + 1) + 4) = 1;
  survarium::flash_text::set_font_size(
    v8,
    (Scaleform::GFx::DrawTextManager ***)&player.m_object->m_animation_player.m_tree_buffers[0][14296]);
  if ( player.m_object->m_animation_player.m_tree_buffers[0][14304] != 1 )
  {
    v9 = *(_DWORD *)v7;
    player.m_object->m_animation_player.m_tree_buffers[0][14304] = 1;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 152))(v9, 1);
    *(_BYTE *)(*(_DWORD *)&player.m_object->m_animation_player.m_tree_buffers[0][14300] + 4) = 1;
  }
  v10 = player.m_object->m_speed_parameters.m_multipliers.m_buffer[2];
  v11 = *(_DWORD *)(*(_DWORD *)&v10 + 8);
  v12 = *(_DWORD *)v7;
  result.Width = *(float *)(*(_DWORD *)&v10 + 12);
  v13 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v12 + 76))(v12, v24);
  v19 = *(float *)(v13 + 12) - *(float *)(v13 + 4);
  v14 = (float *)(*(int (__thiscall **)(_DWORD, _BYTE *))(**(_DWORD **)v7 + 76))(*(_DWORD *)v7, v25);
  result.Width = (double)LODWORD(result.Width) - v19;
  v20 = ((double)v11 - (v14[2] - *v14)) * 0.5;
  v15 = (float *)(*(int (__thiscall **)(_DWORD, _BYTE *))(**(_DWORD **)v7 + 76))(*(_DWORD *)v7, v26);
  v16 = v15[2] - *v15;
  v17 = v15[3] - v15[1];
  viewRect.x1 = v20;
  viewRect.y1 = result.Width;
  v18 = *(_DWORD *)v7;
  viewRect.x2 = v16 + v20;
  viewRect.y2 = v17 + result.Width;
  (*(void (__thiscall **)(int, Scaleform::Render::Rect<float> *))(*(_DWORD *)v18 + 72))(v18, &viewRect);
  *(_BYTE *)(*(_DWORD *)&player.m_object->m_animation_player.m_tree_buffers[0][14300] + 4) = 1;
  player.m_object->m_animation_player.m_tree_buffers[0][14308] = 1;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a3);
}
