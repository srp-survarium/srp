void __thiscall survarium::lobby_menu::fill_skills_tree(
        survarium::lobby_menu *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  char pointer; // al
  survarium::flash_movie *v4; // ecx
  vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  char **v7; // eax
  survarium::flash_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // eax
  vostok::configs::binary_config_value *v10; // eax
  char **v11; // eax
  survarium::flash_value *v12; // ecx
  vostok::configs::binary_config_value *v13; // eax
  vostok::configs::binary_config_value *v14; // eax
  unsigned int *v15; // eax
  survarium::flash_value *v16; // ecx
  survarium::flash_value *v17; // ecx
  survarium::flash_value *v18; // ecx
  survarium::flash_value *v19; // ecx
  survarium::flash_value *v20; // ecx
  survarium::flash_value *v21; // ecx
  int v22; // eax
  int v23; // ecx
  vostok::configs::binary_config_value *v24; // eax
  vostok::configs::binary_config_value *v25; // eax
  survarium::flash_movie *v26; // ecx
  survarium::flash_value *v27; // ecx
  vostok::configs::binary_config_value *v28; // ecx
  bool v29; // al
  survarium::flash_value *v30; // ecx
  survarium::flash_value *v31; // ecx
  const vostok::configs::binary_config_value *v32; // eax
  survarium::flash_movie *v33; // ecx
  unsigned int m_uid; // eax
  const vostok::configs::binary_config_value *v35; // eax
  float v36; // xmm0_4
  const vostok::configs::binary_config_value *v37; // eax
  vostok::configs::binary_config_value *v38; // eax
  vostok::configs::binary_config_value *v39; // eax
  char **v40; // eax
  survarium::flash_value *v41; // ecx
  survarium::flash_value *v42; // ecx
  vostok::configs::binary_config_value *v43; // eax
  vostok::configs::binary_config_value *v44; // eax
  unsigned int *v45; // eax
  survarium::flash_value *v46; // ecx
  survarium::flash_value *v47; // ecx
  vostok::configs::binary_config_value *v48; // ecx
  const vostok::configs::binary_config_value *v49; // eax
  vostok::configs::binary_config_value *v50; // ecx
  unsigned int v51; // eax
  vostok::configs::binary_config_value *v52; // eax
  vostok::configs::binary_config_value *v53; // eax
  char **v54; // eax
  vostok::configs::binary_config_value *v55; // eax
  vostok::configs::binary_config_value *v56; // eax
  char **v57; // eax
  survarium::flash_value *v58; // ecx
  survarium::flash_value *v59; // ecx
  survarium::flash_value *v60; // ecx
  survarium::flash_value *v61; // ecx
  int v62; // esi
  survarium::text_translator v63[128]; // [esp+18h] [ebp-964h] BYREF
  survarium::text_translator v64[128]; // [esp+218h] [ebp-764h] BYREF
  survarium::text_translator value[128]; // [esp+418h] [ebp-564h] BYREF
  survarium::text_translator v66[129]; // [esp+618h] [ebp-364h] BYREF
  char _Dest[32]; // [esp+81Ch] [ebp-160h] BYREF
  char v68[32]; // [esp+83Ch] [ebp-140h] BYREF
  char v69[32]; // [esp+85Ch] [ebp-120h] BYREF
  char v70[32]; // [esp+87Ch] [ebp-100h] BYREF
  _QWORD v71[4]; // [esp+89Ch] [ebp-E0h] BYREF
  Scaleform::GFx::Value v72; // [esp+8BCh] [ebp-C0h] BYREF
  survarium::flash_value v73; // [esp+8D4h] [ebp-A8h] BYREF
  Scaleform::GFx::Value pargs; // [esp+8ECh] [ebp-90h] BYREF
  unsigned int v75; // [esp+904h] [ebp-78h]
  vostok::resources::resource_link *m_last; // [esp+908h] [ebp-74h]
  survarium::flash_value v77; // [esp+90Ch] [ebp-70h] BYREF
  survarium::flash_value v78; // [esp+924h] [ebp-58h] BYREF
  Scaleform::GFx::Value v79; // [esp+93Ch] [ebp-40h] BYREF
  int v80; // [esp+954h] [ebp-28h]
  float v81; // [esp+958h] [ebp-24h]
  vostok::configs::binary_config_value *v82; // [esp+95Ch] [ebp-20h]
  unsigned int v83; // [esp+960h] [ebp-1Ch]
  int v84; // [esp+964h] [ebp-18h]
  int v85; // [esp+968h] [ebp-14h]
  vostok::resources::unmanaged_resource *v86; // [esp+96Ch] [ebp-10h]
  int i; // [esp+970h] [ebp-Ch]
  vostok::configs::binary_config_value *v88; // [esp+974h] [ebp-8h]

  m_object = a2.m_object;
  m_last = a2.m_object[2].m_next_in_memory_type[1].m_children_resources.m_last;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &a2,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&a2.m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3412]->m_name[217]);
  v86 = a2.m_object->m_lods[0].m_template.m_object;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
  *(_DWORD *)v78.body = 0;
  *(_DWORD *)&v78.body[4] = 0;
  v84 = 1;
  v80 = 5;
  do
  {
    sprintf_s<32>((char (*)[32])_Dest, "skill_%d", v84);
    v82 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)m_last, _Dest);
    pointer = (char)vostok::configs::binary_config_value::operator[](v82, "id")->data.pointer;
    pargs.pObjectInterface = 0;
    pargs.Type = VT_Undefined;
    HIBYTE(a2.m_object) = pointer;
    survarium::flash_movie::CreateObject(v4, *(survarium::flash_value **)(m_object[2].m_uid + 264), &pargs);
    a2.m_object = (vostok::particle::particle_system_instance_impl *)HIBYTE(a2.m_object);
    sprintf_s<32>((char (*)[32])v69, "skill_%d", a2.m_object);
    v5 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v86, "skills_dict");
    v6 = vostok::configs::binary_config_value::operator[](v5, v69);
    v7 = (char **)vostok::configs::binary_config_value::operator[](v6, "skill_name");
    survarium::text_translator::translate_text(
      value,
      (int)&m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3421],
      *v7,
      (char *)value);
    survarium::flash_value::SetString(&v78, (const char *)value);
    survarium::flash_value::SetMember(v8, &pargs, "name", &v78);
    v9 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v86, "skills_dict");
    v10 = vostok::configs::binary_config_value::operator[](v9, v69);
    v11 = (char **)vostok::configs::binary_config_value::operator[](v10, "skill_description");
    survarium::text_translator::translate_text(
      v64,
      (int)&m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3421],
      *v11,
      (char *)v64);
    survarium::flash_value::SetString(&v78, (const char *)v64);
    survarium::flash_value::SetMember(v12, &pargs, "description", &v78);
    v13 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v86, "skills_dict");
    v14 = vostok::configs::binary_config_value::operator[](v13, v69);
    v15 = (unsigned int *)vostok::configs::binary_config_value::operator[](v14, "skill_icon");
    survarium::flash_value::SetUInt(v16, (int)&v78, *v15);
    survarium::flash_value::SetMember(v17, &pargs, "color", &v78);
    survarium::flash_value::SetUInt(v18, (int)&v78, (unsigned int)a2.m_object);
    survarium::flash_value::SetMember(v19, &pargs, "id", &v78);
    survarium::flash_value::SetUInt(v20, (int)&v78, 0);
    survarium::flash_value::SetMember(v21, &pargs, "opened", &v78);
    Scaleform::GFx::Movie::CreateArray(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(m_object[2].m_uid + 264) + 4),
      (Scaleform::GFx::Value *)&v78);
    *(_DWORD *)v77.body = 0;
    *(_DWORD *)&v77.body[4] = 0;
    v22 = 24 * vostok::configs::binary_config_value::operator[](v82, "levels")->count / 24;
    v23 = 1;
    v85 = 1;
    v75 = v22;
    if ( v22 )
    {
      do
      {
        sprintf_s<32>((char (*)[32])v68, "skill_level_%d", v85);
        v24 = vostok::configs::binary_config_value::operator[](v82, "levels");
        v25 = vostok::configs::binary_config_value::operator[](v24, v68);
        v72.pObjectInterface = 0;
        v72.Type = VT_Undefined;
        v88 = v25;
        survarium::flash_movie::CreateObject(v26, *(survarium::flash_value **)(m_object[2].m_uid + 264), &v72);
        survarium::flash_value::SetString(&v77, (const char *)value);
        survarium::flash_value::SetMember(v27, &v72, "name", &v77);
        v29 = vostok::configs::binary_config_value::value_exists(v28, (int)v88, (unsigned int)"perks");
        survarium::flash_value::SetUInt(v30, (int)&v77, v29);
        survarium::flash_value::SetMember(v31, &v72, "power", &v77);
        Scaleform::GFx::Movie::CreateArray(
          *(Scaleform::GFx::Movie **)(*(_DWORD *)(m_object[2].m_uid + 264) + 4),
          (Scaleform::GFx::Value *)&v77);
        a2.m_object = (vostok::particle::particle_system_instance_impl *)vostok::configs::binary_config_value::operator[](
                                                                           v88,
                                                                           "boosters")->data.pointer;
        v32 = vostok::configs::binary_config_value::operator[](v88, "boosters");
        v33 = (survarium::flash_movie *)((char *)v32->data.pointer + 24 * v32->count);
        v83 = (unsigned int)v33;
        *(_DWORD *)v73.body = 0;
        *(_DWORD *)&v73.body[4] = 0;
        i = 0;
        if ( (survarium::flash_movie *)a2.m_object != v33 )
        {
          do
          {
            m_uid = m_object[2].m_uid;
            v79.pObjectInterface = 0;
            v79.Type = VT_Undefined;
            survarium::flash_movie::CreateObject(v33, *(survarium::flash_value **)(m_uid + 264), &v79);
            v35 = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)a2.m_object,
                    "value");
            if ( v35->type == 2 )
              v36 = *(float *)&v35->data.pointer;
            else
              v36 = (float)(int)v35->data.pointer;
            v81 = v36;
            v37 = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)a2.m_object,
                    "id");
            sprintf_s<32>((char (*)[32])v71, "booster_%d", v37->data.pointer);
            v38 = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)v86,
                    "boosters_dict");
            v39 = vostok::configs::binary_config_value::operator[](v38, (char *)v71);
            v40 = (char **)vostok::configs::binary_config_value::operator[](v39, "booster_name");
            survarium::text_translator::translate_text(
              v66,
              (int)&m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3421],
              *v40,
              (char *)v66);
            sprintf_s<32>((char (*)[32])v70, "%f", v81);
            survarium::flash_value::SetString(&v73, v70);
            survarium::flash_value::SetMember(v41, &v79, "prop_value", &v73);
            survarium::flash_value::SetString(&v73, (const char *)v66);
            survarium::flash_value::SetMember(v42, &v79, "prop_name", &v73);
            v43 = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)v86,
                    "boosters_dict");
            v44 = vostok::configs::binary_config_value::operator[](v43, (char *)v71);
            v45 = (unsigned int *)vostok::configs::binary_config_value::operator[](v44, "booster_icon");
            survarium::flash_value::SetUInt(v46, (int)&v73, *v45);
            survarium::flash_value::SetMember(v47, &v79, "prop_icon", &v73);
            (*(void (__thiscall **)(_DWORD, _DWORD, int, Scaleform::GFx::Value *))(**(_DWORD **)v77.body + 52))(
              *(_DWORD *)v77.body,
              *(_DWORD *)&v77.body[8],
              i,
              &v79);
            Scaleform::GFx::Value::~Value(&v79);
            a2.m_object = (vostok::particle::particle_system_instance_impl *)((char *)a2.m_object + 24);
            ++i;
          }
          while ( a2.m_object != (vostok::particle::particle_system_instance_impl *)v83 );
        }
        survarium::flash_value::SetMember((survarium::flash_value *)v33, &v72, "properties", &v77);
        if ( vostok::configs::binary_config_value::value_exists(v48, (int)v88, (unsigned int)"perks") )
        {
          Scaleform::GFx::Movie::CreateArray(
            *(Scaleform::GFx::Movie **)(*(_DWORD *)(m_object[2].m_uid + 264) + 4),
            (Scaleform::GFx::Value *)&v77);
          a2.m_object = (vostok::particle::particle_system_instance_impl *)vostok::configs::binary_config_value::operator[](
                                                                             v88,
                                                                             "perks")->data.pointer;
          v49 = vostok::configs::binary_config_value::operator[](v88, "perks");
          v50 = (vostok::configs::binary_config_value *)((char *)v49->data.pointer + 24 * v49->count);
          v79.pObjectInterface = 0;
          v88 = v50;
          v79.Type = VT_Undefined;
          for ( i = 0; (vostok::configs::binary_config_value *)a2.m_object != v88; ++i )
          {
            v51 = m_object[2].m_uid;
            v71[1] = 0;
            survarium::flash_movie::CreateObject(
              (survarium::flash_movie *)v50,
              *(survarium::flash_value **)(v51 + 264),
              (Scaleform::GFx::Value *)&v71[1]);
            v83 = (unsigned int)vostok::configs::binary_config_value::operator[](
                                  (vostok::configs::binary_config_value *)a2.m_object,
                                  "id")->data.pointer;
            sprintf_s<32>((char (*)[32])v70, "perk_%d", v83);
            v52 = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)v86,
                    "perks_dict");
            v53 = vostok::configs::binary_config_value::operator[](v52, v70);
            v54 = (char **)vostok::configs::binary_config_value::operator[](v53, "name");
            survarium::text_translator::translate_text(
              v66,
              (int)&m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3421],
              *v54,
              (char *)v66);
            v55 = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)v86,
                    "perks_dict");
            v56 = vostok::configs::binary_config_value::operator[](v55, v70);
            v57 = (char **)vostok::configs::binary_config_value::operator[](v56, "description");
            survarium::text_translator::translate_text(
              v63,
              (int)&m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3421],
              *v57,
              (char *)v63);
            survarium::flash_value::SetString((survarium::flash_value *)&v79, (const char *)v66);
            survarium::flash_value::SetMember(v58, &v71[1], "name", (survarium::flash_value *)&v79);
            survarium::flash_value::SetString((survarium::flash_value *)&v79, (const char *)v63);
            survarium::flash_value::SetMember(v59, &v71[1], "item_description", (survarium::flash_value *)&v79);
            survarium::flash_value::SetUInt(v60, (int)&v79, v83);
            survarium::flash_value::SetMember(v61, &v71[1], "id", (survarium::flash_value *)&v79);
            (*(void (__thiscall **)(_DWORD, _DWORD, int, _QWORD *))(**(_DWORD **)v77.body + 52))(
              *(_DWORD *)v77.body,
              *(_DWORD *)&v77.body[8],
              i,
              &v71[1]);
            Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v71[1]);
            a2.m_object = (vostok::particle::particle_system_instance_impl *)((char *)a2.m_object + 24);
          }
          survarium::flash_value::SetMember((survarium::flash_value *)v50, &v72, "perks", &v77);
          Scaleform::GFx::Value::~Value(&v79);
        }
        v62 = v85;
        (*(void (__thiscall **)(_DWORD, _DWORD, int, Scaleform::GFx::Value *))(**(_DWORD **)v78.body + 52))(
          *(_DWORD *)v78.body,
          *(_DWORD *)&v78.body[8],
          v85 - 1,
          &v72);
        Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v73);
        Scaleform::GFx::Value::~Value(&v72);
        v85 = v62 + 1;
      }
      while ( v62 + 1 <= v75 );
    }
    survarium::flash_value::SetMember((survarium::flash_value *)v23, &pargs, "slots", &v78);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(m_object[2].m_uid + 264) + 4),
      "root.create_perk_tree",
      0,
      &pargs,
      1u);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v77);
    Scaleform::GFx::Value::~Value(&pargs);
    ++v84;
    --v80;
  }
  while ( v80 );
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v78);
}
