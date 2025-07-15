void __thiscall vostok::resources::game_resources_manager::on_unmount_started_callback(
        vostok::resources::game_resources_manager *this)
{
  vostok::resources::game_resources_manager::dispatch_capture(this, this);
}
