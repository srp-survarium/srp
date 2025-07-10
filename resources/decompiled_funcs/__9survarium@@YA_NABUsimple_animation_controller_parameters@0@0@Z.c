BOOL __usercall survarium::operator!=@<eax>(
        const survarium::simple_animation_controller_parameters *first@<eax>,
        const survarium::simple_animation_controller_parameters *second@<edx>)
{
  return first->emitter.m_object != second->emitter.m_object;
}
