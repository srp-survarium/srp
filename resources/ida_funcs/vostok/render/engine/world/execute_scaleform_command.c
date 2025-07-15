void __thiscall vostok::render::engine::world::execute_scaleform_command(
        vostok::render::engine::world *this,
        survarium::scaleform_render_command command)
{
  command.thread_command->Execute(command.thread_command);
}
