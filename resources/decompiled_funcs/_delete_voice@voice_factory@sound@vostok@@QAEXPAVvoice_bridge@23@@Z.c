void __thiscall vostok::sound::voice_factory::delete_voice(
        vostok::sound::voice_factory *this,
        vostok::sound::voice_bridge *voice_to_be_deleted)
{
  vostok::sound::voice_bridge::set_handler(voice_to_be_deleted, 0);
  vostok::sound::voice_bridge::set_output_voice(voice_to_be_deleted, 0);
}
