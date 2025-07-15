void __userpurge vostok::animation::hand_to_weapon_ik_solver::initialize_locators(
        vostok::animation::hand_to_weapon_ik_solver *this@<ecx>,
        vostok::render::model_locator_item *a2@<eax>,
        vostok::render::render_model_instance *item_model)
{
  vostok::render::render_model_instance *v3; // esi
  vostok::render::model_locator_item *v4; // ebx
  vostok::fixed_string<32> *v5; // eax
  int v6; // ebx
  vostok::fixed_string<32> *v7; // eax
  _DWORD v8[11]; // [esp+Ch] [ebp-88h] BYREF
  vostok::buffer_string v9[3]; // [esp+38h] [ebp-5Ch] BYREF
  _DWORD v10[3]; // [esp+64h] [ebp-30h]
  _DWORD v11[3]; // [esp+70h] [ebp-24h]
  _DWORD v12[2]; // [esp+7Ch] [ebp-18h]
  int v13; // [esp+84h] [ebp-10h]
  const char *v14; // [esp+88h] [ebp-Ch]
  vostok::render::model_locator_item *v15; // [esp+8Ch] [ebp-8h]
  int m_name; // [esp+90h] [ebp-4h]

  v13 = 0;
  v12[0] = "LeftHand";
  v12[1] = "RightHand";
  v10[0] = "%s_idle";
  v10[1] = "%s_reload";
  v10[2] = "%s_reload_pivot";
  v11[0] = "%s_idle_3rdView";
  v11[1] = "%s_reload_3rdView";
  v11[2] = "%s_reload_pivot_3rdView";
  v15 = a2;
  do
  {
    v14 = (const char *)v12[v13];
    vostok::fixed_string<32>::createf(v9, (vostok::fixed_string<32> *)"%s_idle", v14);
    v3 = item_model;
    if ( item_model->get_locator(item_model, v9[0].m_begin, v15) )
    {
      m_name = 1;
      v4 = v15 + 1;
      do
      {
        v5 = vostok::fixed_string<32>::createf(v8, (vostok::fixed_string<32> *)v10[m_name], v14);
        if ( v9 != v5 )
          vostok::buffer_string::operator=(v5, v9);
        if ( !v3->get_locator(v3, v9[0].m_begin, v4) )
        {
          qmemcpy(v4, v15, sizeof(vostok::render::model_locator_item));
          v3 = item_model;
        }
        ++m_name;
        ++v4;
      }
      while ( m_name != 3 );
      v6 = 0;
      v14 = (const char *)v15;
      m_name = (int)v15[3].m_name;
      do
      {
        v7 = vostok::fixed_string<32>::createf(v8, (vostok::fixed_string<32> *)v11[v6], (const char *)v12[v13]);
        if ( v9 != v7 )
          vostok::buffer_string::operator=(v7, v9);
        if ( !item_model->get_locator(item_model, v9[0].m_begin, (vostok::render::model_locator_item *)m_name) )
          qmemcpy((void *)m_name, v14, 0x64u);
        m_name += 100;
        v14 += 100;
        ++v6;
      }
      while ( v6 != 3 );
    }
    ++v13;
    v15 = (vostok::render::model_locator_item *)((char *)v15 + 628);
  }
  while ( v13 != 2 );
}
