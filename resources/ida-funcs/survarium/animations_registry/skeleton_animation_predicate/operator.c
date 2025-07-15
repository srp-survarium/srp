bool __usercall survarium::animations_registry::skeleton_animation_predicate::operator()@<al>(
        const survarium::animations_registry::animations_tuple *left@<esi>,
        const survarium::animations_registry::animations_tuple *right@<edx>,
        survarium::animations_registry::skeleton_animation_predicate *this)
{
  if ( left->first_view.m_object < right->first_view.m_object )
    return 1;
  if ( left->first_view.m_object <= right->first_view.m_object )
    return left->third_view.m_object < right->third_view.m_object;
  return 0;
}
