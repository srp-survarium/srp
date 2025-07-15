DNameStatusNode *__cdecl DNameStatusNode::make(DNameStatus stat)
{
  if ( (`DNameStatusNode::make'::`2'::`local static guard' & 1) == 0 )
  {
    `DNameStatusNode::make'::`2'::`local static guard' |= 1u;
    `DNameStatusNode::make'::`2'::nodes[0].__vftable = (DNameStatusNode_vtbl *)&DNameStatusNode::`vftable';
    dword_A9AFB8 = 0;
    dword_A9AFBC = 0;
    dword_A9AFC0 = (int)&DNameStatusNode::`vftable';
    dword_A9AFC4 = 1;
    dword_A9AFC8 = 4;
    dword_A9AFCC = (int)&DNameStatusNode::`vftable';
    dword_A9AFD0 = 2;
    dword_A9AFD4 = 0;
    dword_A9AFD8 = (int)&DNameStatusNode::`vftable';
    dword_A9AFDC = 3;
    dword_A9AFE0 = 0;
  }
  if ( (unsigned int)stat > DN_error )
    return (DNameStatusNode *)&dword_A9AFD8;
  else
    return &`DNameStatusNode::make'::`2'::nodes[stat];
}
