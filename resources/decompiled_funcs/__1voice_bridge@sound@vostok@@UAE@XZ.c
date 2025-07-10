void __thiscall vostok::sound::voice_bridge::~voice_bridge(vostok::sound::voice_bridge *this)
{
  this->__vftable = (vostok::sound::voice_bridge_vtbl *)&vostok::sound::voice_bridge::`vftable';
  this->m_source_voice->DestroyVoice(this->m_source_voice);
}
