void __userpurge survarium::players_checker::serialize(
        survarium::players_checker *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::buffer_writer *writer)
{
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)(a2 + 32),
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\respawn_point_core.cpp",
    (const char *)0x28,
    "survarium::players_checker::serialize",
    "m_inside_objects_count");
}
