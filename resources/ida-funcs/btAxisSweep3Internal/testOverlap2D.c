bool __userpurge btAxisSweep3Internal<unsigned short>::testOverlap2D@<al>(
        const btAxisSweep3Internal<unsigned short>::Handle *pHandleA@<esi>,
        int axis0@<eax>,
        int axis1@<ecx>,
        const btAxisSweep3Internal<unsigned short>::Handle *pHandleB)
{
  int v4; // eax
  int v5; // ecx
  bool result; // al

  result = 0;
  if ( pHandleB->m_maxEdges[axis0] >= pHandleA->m_minEdges[axis0] )
  {
    v4 = 2 * axis1 + 54;
    v5 = 2 * axis1 + 48;
    if ( *(_WORD *)((char *)&pHandleA->m_clientObject + v4) >= *(_WORD *)((char *)&pHandleB->m_clientObject + v5)
      && *(_WORD *)((char *)&pHandleB->m_clientObject + v4) >= *(_WORD *)((char *)&pHandleA->m_clientObject + v5) )
    {
      return 1;
    }
  }
  return result;
}
