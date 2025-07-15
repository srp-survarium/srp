void __userpurge survarium::weapon_sound_effect::serialize(
        survarium::weapon_sound_effect *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer::w(
    (vostok::network_core::buffer_writer *)this,
    client_writer,
    (unsigned __int8 *)(a2 + 57),
    1u);
}
