void __thiscall dynamic_initializer_for__g_debug_render_device__(vostok::command_line::key *this)
{
  vostok::command_line::key::key(
    this,
    &g_debug_render_device,
    "debug_dx",
    uri,
    (const char *)&initiator_raw.initiator_tree,
    "create d3d device with D3D_CREATE_DEVICE_DEBUG flag",
    uri);
}
