void __thiscall vostok::sound::sound_rms_cook::on_sub_resources_loaded(
        vostok::sound::sound_rms_cook *this,
        vostok::resources::queries_result *data)
{
  unsigned int v2; // eax
  vostok::resources::query_result_for_cook *v3; // ecx
  int v4; // eax
  ov_callbacks value; // [esp-Ch] [ebp-3E0h] BYREF
  int v6; // [esp+4h] [ebp-3D0h]
  unsigned __int64 v7; // [esp+8h] [ebp-3CCh]
  unsigned __int64 v8; // [esp+10h] [ebp-3C4h]
  __int64 v9; // [esp+18h] [ebp-3BCh]
  __int64 v10; // [esp+20h] [ebp-3B4h]
  __int64 v11; // [esp+28h] [ebp-3ACh]
  int v12; // [esp+30h] [ebp-3A4h]
  unsigned __int16 v13; // [esp+36h] [ebp-39Eh]
  vostok::sound::sound_rms_cook *thisa; // [esp+38h] [ebp-39Ch]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v15; // [esp+50h] [ebp-384h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_m_managed_resource; // [esp+54h] [ebp-380h]
  char v17; // [esp+5Bh] [ebp-379h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v18; // [esp+5Ch] [ebp-378h]
  const unsigned __int8 *m_data; // [esp+60h] [ebp-374h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *p_tell_func; // [esp+74h] [ebp-360h]
  vostok::resources::memory_type *v21; // [esp+78h] [ebp-35Ch]
  unsigned int v22; // [esp+7Ch] [ebp-358h]
  vostok::resources::managed_resource *object; // [esp+80h] [ebp-354h]
  float out_value; // [esp+98h] [ebp-33Ch] BYREF
  vostok::resources::managed_resource *m_object; // [esp+9Ch] [ebp-338h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v26; // [esp+A0h] [ebp-334h] BYREF
  vostok::resources::query_result_for_user *v27; // [esp+A4h] [ebp-330h]
  vostok::sound::sound_rms *v28; // [esp+ACh] [ebp-328h]
  char v29; // [esp+B7h] [ebp-31Dh]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> created_resource; // [esp+B8h] [ebp-31Ch] BYREF
  unsigned __int64 samples_discr_in_pcm; // [esp+BCh] [ebp-318h]
  unsigned int discretization; // [esp+C8h] [ebp-30Ch]
  unsigned int size; // [esp+CCh] [ebp-308h]
  vostok::resources::query_result_for_cook *parent; // [esp+D0h] [ebp-304h]
  OggVorbis_File ovf; // [esp+D4h] [ebp-300h] BYREF
  vostok::resources::pinned_ptr_mutable<vostok::sound::sound_rms> pinned_ptr; // [esp+3A4h] [ebp-30h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ogg_raw_file; // [esp+3B0h] [ebp-24h] BYREF
  vorbis_info *ovi; // [esp+3B4h] [ebp-20h]
  float discr; // [esp+3B8h] [ebp-1Ch]
  ov_callbacks ovc; // [esp+3BCh] [ebp-18h]
  vostok::sound::ogg_file_source ogg; // [esp+3CCh] [ebp-8h] BYREF

  thisa = this;
  v29 = 0;
  parent = data->m_parent_query;
  v27 = vostok::resources::queries_result::operator[](data, 0);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &ogg_raw_file,
    &v27->m_managed_resource);
  ogg.resource.m_object = 0;
  v26.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v26,
    &ogg_raw_file);
  m_object = v26.m_object;
  v26.m_object = ogg.resource.m_object;
  ogg.resource.m_object = m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v26);
  ogg.pointer = 0;
  ovc.read_func = vostok::sound::ogg_utils::ov_read_func;
  ovc.seek_func = vostok::sound::ogg_utils::ov_seek_func;
  ovc.close_func = vostok::sound::ogg_utils::ov_close_func;
  ovc.tell_func = vostok::sound::ogg_utils::ov_tell_func;
  value.read_func = vostok::sound::ogg_utils::ov_read_func;
  value.seek_func = vostok::sound::ogg_utils::ov_seek_func;
  value.close_func = vostok::sound::ogg_utils::ov_close_func;
  value.tell_func = vostok::sound::ogg_utils::ov_tell_func;
  ov_open_callbacks(&ogg, &ovf, 0, 0, value);
  ovi = ov_info(&ovf, -1);
  discretization = 50;
  if ( vostok::command_line::key::is_set(&s_discr_frequency) )
  {
    out_value = *(float *)&FLOAT_0_0;
    if ( vostok::command_line::key::is_set_as_number(&s_discr_frequency, &out_value) )
    {
      v12 = v13 | 0xC00;
      v11 = (__int64)out_value;
      discretization = v11;
    }
  }
  v10 = discretization;
  discr = 1.0 / (double)discretization;
  samples_discr_in_pcm = (unsigned __int64)((double)ovi->rate * discr);
  v9 = ov_pcm_total(&ovf, -1);
  v8 = samples_discr_in_pcm & 0x7FFFFFFFFFFFFFFFLL;
  v7 = samples_discr_in_pcm & 0x8000000000000000uLL;
  *(float *)&value.tell_func = (double)v9 / (double)samples_discr_in_pcm;
  size = vostok::math::ceil(*(float *)&value.tell_func);
  ov_clear(&ovf);
  object = vostok::resources::allocate_managed_resource(4 * size + 16, sound_rms_class);
  created_resource.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &created_resource,
    object);
  if ( created_resource.m_object )
  {
    p_tell_func = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&value.tell_func;
    value.tell_func = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&value.tell_func,
      &created_resource);
    vostok::resources::cook_base::pin_for_write<vostok::sound::sound_rms>(
      thisa,
      &pinned_ptr,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)value.tell_func);
    m_data = pinned_ptr.m_data;
    v28 = (vostok::sound::sound_rms *)pinned_ptr.m_data;
    if ( pinned_ptr.m_data )
    {
      vostok::sound::sound_rms::sound_rms(v28, &ogg_raw_file, discr);
      v6 = v4;
    }
    else
    {
      v6 = 0;
    }
    v18 = &v15;
    v15.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v15,
      &created_resource);
    v17 = 0;
    p_m_managed_resource = &parent->m_managed_resource;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
      &parent->m_managed_resource,
      &v15);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v15);
    vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
    vostok::resources::pinned_ptr_base<vostok::sound::sound_rms>::~pinned_ptr_base<vostok::sound::sound_rms>(&pinned_ptr);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&created_resource);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&ogg.resource);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&ogg_raw_file);
  }
  else
  {
    v21 = &vostok::resources::managed_memory;
    v22 = 4 * size + 16;
    v2 = v22;
    v3 = parent;
    parent->m_out_of_memory.type = &vostok::resources::managed_memory;
    v3->m_out_of_memory.size = v2;
    vostok::resources::query_result_for_cook::finish_query(parent, result_out_of_memory, assert_on_fail_true);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&created_resource);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&ogg.resource);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&ogg_raw_file);
  }
}
