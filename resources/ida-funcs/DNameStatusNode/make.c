DNameStatusNode *__cdecl DNameStatusNode::make(unsigned int stat)
{
  if ( (`DNameStatusNode::make'::`2'::`local static guard' & 1) == 0 )
  {
    `DNameStatusNode::make'::`2'::`local static guard' |= 1u;
    `DNameStatusNode::make'::`2'::nodes[0].__vftable = (DNameStatusNode_vtbl *)&DNameStatusNode::`vftable';
    dword_8E4BB0 = 0;
    dword_8E4BB4 = 0;
    dword_8E4BB8 = (int)&DNameStatusNode::`vftable';
    dword_8E4BBC = 1;
    dword_8E4BC0 = 4;
    dword_8E4BC4 = (int)&DNameStatusNode::`vftable';
    dword_8E4BC8 = 2;
    dword_8E4BCC = 0;
    dword_8E4BD0 = (int)&DNameStatusNode::`vftable';
    dword_8E4BD4 = 3;
    dword_8E4BD8 = 0;
  }
  if ( stat > 3 )
    return (DNameStatusNode *)&dword_8E4BD0;
  else
    return &`DNameStatusNode::make'::`2'::nodes[stat];
}
