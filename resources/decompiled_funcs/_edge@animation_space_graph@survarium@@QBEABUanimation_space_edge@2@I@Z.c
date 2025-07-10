const survarium::animation_space_edge *__usercall survarium::animation_space_graph::edge@<eax>(
        survarium::animation_space_graph *this@<ecx>,
        int a2@<eax>)
{
  return (const survarium::animation_space_edge *)(a2
                                                 + 292 * *(_DWORD *)(a2 + 276)
                                                 + 8 * (5 * (_DWORD)this + *(_DWORD *)(a2 + 280))
                                                 + 288);
}
