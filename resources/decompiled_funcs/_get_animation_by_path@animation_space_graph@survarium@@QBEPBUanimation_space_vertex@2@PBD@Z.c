survarium::animation_space_graph *__usercall survarium::animation_space_graph::get_animation_by_path@<eax>(
        survarium::animation_space_graph *this@<ecx>,
        const char *animation_path@<edi>)
{
  survarium::animation_space_graph *result; // eax
  survarium::animation_space_graph *v3; // esi

  result = this + 1;
  v3 = (survarium::animation_space_graph *)((char *)this + 292 * this->m_animations_count + 288);
  if ( &this[1] == v3 )
    return 0;
  while ( strcmp((const char *)result->type, animation_path) )
  {
    result = (survarium::animation_space_graph *)((char *)result + 292);
    if ( result == v3 )
      return 0;
  }
  return result;
}
