void __thiscall survarium::scaleform_render_command_queue_impl::PushThreadCommand(
        survarium::scaleform_render_command_queue_impl *this,
        Scaleform::Render::ThreadCommand *command)
{
  ((void (__thiscall *)(survarium::scaleform_game_engine *, Scaleform::Render::ThreadCommand *))this->engine->execute_scaleform_command)(
    this->engine,
    command);
}
