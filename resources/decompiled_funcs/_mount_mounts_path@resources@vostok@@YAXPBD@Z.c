void __thiscall vostok::resources::mount_mounts_path(vostok::resources::resources_manager *mounts_path)
{
  vostok::resources::resources_manager::mount_mounts_path(
    mounts_path,
    (int)vostok::resources::g_resources_manager.m_variable,
    (vostok::resources *)mounts_path);
}
