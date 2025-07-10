void __usercall stlp_std::priv::__linear_insert<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
        vostok::render::grass_patch::sort_info *__first@<esi>,
        vostok::render::grass_patch::sort_info *__last@<ecx>,
        vostok::render::grass_patch::sort_info __val,
        vostok::render::sort_indices_predicate __comp)
{
  unsigned int num_indices; // eax

  if ( (float)((float)((float)((float)(__first->position.z - __comp.m_view_pos.z)
                             * (float)(__first->position.z - __comp.m_view_pos.z))
                     + (float)((float)(__first->position.y - __comp.m_view_pos.y)
                             * (float)(__first->position.y - __comp.m_view_pos.y)))
             + (float)((float)(__first->position.x - __comp.m_view_pos.x)
                     * (float)(__first->position.x - __comp.m_view_pos.x))) <= (float)((float)((float)((float)(__val.position.z - __comp.m_view_pos.z) * (float)(__val.position.z - __comp.m_view_pos.z))
                                                                                             + (float)((float)(__val.position.y - __comp.m_view_pos.y) * (float)(__val.position.y - __comp.m_view_pos.y)))
                                                                                     + (float)((float)(__val.position.x - __comp.m_view_pos.x)
                                                                                             * (float)(__val.position.x - __comp.m_view_pos.x))) )
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::render::grass_patch::sort_info *,vostok::render::grass_patch::sort_info,vostok::render::sort_indices_predicate>(
      __last,
      __val,
      __comp);
  }
  else
  {
    if ( (char *)__last - (char *)__first > 0 )
      memmove((unsigned __int8 *)&__first[1], (unsigned __int8 *)__first, (char *)__last - (char *)__first);
    num_indices = __val.num_indices;
    *(_QWORD *)&__first->position.x = *(_QWORD *)&__val.position.x;
    *(_QWORD *)&__first->position.elements[2] = *(_QWORD *)&__val.position.elements[2];
    __first->num_indices = num_indices;
  }
}
