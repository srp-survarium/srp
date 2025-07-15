void __userpurge survarium::fwd_animation_interval_end_time_calculator::fwd_animation_interval_end_time_calculator(
        survarium::fwd_animation_interval_end_time_calculator *this@<ecx>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *a2@<esi>,
        stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *container,
        vostok::resources::managed_resource *animated_object)
{
  survarium::weapon_user_animations_container *v4; // ecx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v5; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v6; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v7; // edi
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *stand_animation; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v9; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v10; // edi
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *sprint_animation; // eax
  int v12; // [esp-Ch] [ebp-5Ch]
  int m_object; // [esp-Ch] [ebp-5Ch]
  _DWORD v14[6]; // [esp+4h] [ebp-4Ch] BYREF
  _DWORD v15[3]; // [esp+1Ch] [ebp-34h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v16; // [esp+28h] [ebp-28h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v17; // [esp+30h] [ebp-20h] BYREF
  int v18; // [esp+38h] [ebp-18h]
  int v19; // [esp+3Ch] [ebp-14h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v20; // [esp+40h] [ebp-10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v21; // [esp+44h] [ebp-Ch]
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *v22; // [esp+48h] [ebp-8h]
  int *v23; // [esp+4Ch] [ebp-4h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v24; // [esp+5Ch] [ebp+Ch]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v25; // [esp+5Ch] [ebp+Ch]

  v15[0] = 0;
  a2->m_object = (vostok::resources::managed_resource *)&survarium::fwd_animation_interval_end_time_calculator::`vftable';
  memset(&a2[2], 0, 0x78u);
  v4 = 0;
  a2[32].m_object = animated_object;
  a2[33].m_object = 0;
  a2[34].m_object = 0;
  v14[0] = 3;
  v14[1] = 4;
  v14[2] = 6;
  v14[3] = 7;
  v14[4] = 24;
  v14[5] = 25;
  v15[1] = 2;
  v15[2] = 4;
  v24 = a2 + 2;
  v19 = 2;
  do
  {
    v5 = v24;
    v22 = 0;
    v25 = v24 + 12;
    v21 = v5;
    do
    {
      LOBYTE(v18) = v22 != 0;
      v23 = v14;
      v6 = v21;
      v21 += 6;
      v20 = v6;
      do
      {
        v12 = *v23;
        v7 = v20++;
        stand_animation = survarium::weapon_user_animations_container::get_stand_animation(
                            v4,
                            container,
                            &v17,
                            v18,
                            v12);
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
          &stand_animation->first,
          v7);
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v17.second);
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v17.first);
        ++v23;
      }
      while ( v23 != v15 );
      v22 = (stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *)((char *)v22 + 1);
    }
    while ( v22 != (stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *)2 );
    v22 = (stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *)v15;
    v9 = v25;
    v24 = v25 + 3;
    v20 = v9;
    do
    {
      m_object = (int)v22->first.m_object;
      v10 = v20++;
      sprint_animation = survarium::weapon_user_animations_container::get_sprint_animation(
                           v4,
                           container,
                           &v16,
                           m_object);
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        &sprint_animation->first,
        v10);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v16.second);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v16.first);
      v22 = (stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *)((char *)v22 + 4);
    }
    while ( v22 != &v16 );
    --v19;
  }
  while ( v19 );
}
