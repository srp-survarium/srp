boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *__cdecl vostok::resources::get_out_of_memory_callback(
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *result)
{
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&s_out_of_memory_callback,
    result);
  return result;
}
