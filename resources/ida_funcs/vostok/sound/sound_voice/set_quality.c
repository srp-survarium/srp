void __thiscall vostok::sound::sound_voice::set_quality(vostok::sound::sound_voice *this, unsigned int quality)
{
  vostok::sound::encoded_sound_interface **v2; // eax
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *other; // [esp+4h] [ebp-6Ch]
  vostok::sound::encoded_sound_interface *v5; // [esp+18h] [ebp-58h]
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp+28h] [ebp-48h] BYREF
  void (__cdecl *f)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // [esp+34h] [ebp-3Ch]
  const vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *v9; // [esp+48h] [ebp-28h]
  int v10; // [esp+4Ch] [ebp-24h]
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v11; // [esp+50h] [ebp-20h] BYREF

  v10 = 0;
  if ( quality != this->m_current_quality
    && !this->m_conv_state
    && vostok::sound::voice_bridge::buffers_queued(this->m_voice) >= 2 )
  {
    v9 = this->m_emitter->dbg_get_encoded_sound(this->m_emitter, quality);
    if ( v9->m_object )
    {
      other = (vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_emitter->dbg_get_encoded_sound(this->m_emitter, quality);
      vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v6,
        other);
      v5 = *v2;
      *v2 = this->m_target_sound_quality.m_object;
      this->m_target_sound_quality.m_object = v5;
      vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v6);
      this->m_current_quality = quality;
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", error) )
      {
        f = vostok::core::g_log_callback;
        v11.vtable = 0;
        boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          &v11,
          vostok::core::g_log_callback);
        v10 |= 1u;
        vostok::logging::append(
          (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v11,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\sound_voice.cpp",
          0xF7u,
          "void __thiscall vostok::sound::sound_voice::set_quality(unsigned int)",
          "sound:",
          error,
          "qality not yet loaded!");
      }
      if ( (v10 & 1) != 0 )
      {
        v10 &= ~1u;
        boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v11);
      }
    }
  }
}
