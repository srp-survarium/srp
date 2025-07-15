void __userpurge vostok::animation::anm_track::load(
        const vostok::configs::binary_config_value *t_root@<eax>,
        vostok::animation::anm_track *this)
{
  const vostok::configs::binary_config_value *v3; // eax
  char *v4; // ebx
  char *v5; // esi
  int channel_id; // eax
  vostok::configs::binary_config_value t; // [esp+10h] [ebp-24h] BYREF
  char *pointer; // [esp+2Ch] [ebp-8h]

  if ( vostok::configs::binary_config_value::operator[](t_root, "version")->data.pointer == (const void *)1 )
  {
    vostok::configs::binary_config_value::operator[](t_root, "channels");
    pointer = (char *)vostok::configs::binary_config_value::operator[](t_root, "channels")->data.pointer;
    v3 = vostok::configs::binary_config_value::operator[](t_root, "channels");
    v4 = (char *)v3->data.pointer + 24 * v3->count;
    while ( pointer != v4 )
    {
      v5 = (char *)*((_DWORD *)pointer + 2);
      channel_id = _stricmp("translateX", v5);
      if ( channel_id )
        channel_id = vostok::animation::anm_track::get_channel_id(v5);
      qmemcpy((void *)&t, pointer, sizeof(t));
      vostok::animation::EtCurve::load(
        (vostok::animation::EtCurve *)this->m_channels,
        (int)this->m_channels[channel_id],
        &t);
      pointer += 24;
    }
    this->m_num_evaluate = 0;
    this->m_evaluate_time = 0.0;
  }
}
