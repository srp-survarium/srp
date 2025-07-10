survarium::scaleform_render_command_queue_impl *__thiscall Scaleform::Render::ThreadCommandQueue::`scalar deleting destructor'(
        survarium::scaleform_render_command_queue_impl *this,
        char a2)
{
  this->__vftable = (survarium::scaleform_render_command_queue_impl_vtbl *)&Scaleform::Render::ThreadCommandQueue::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
