void __usercall btUnionFind::reset(btUnionFind *this@<eax>, int N@<edi>, btUnionFind *a3@<ecx>)
{
  int i; // eax

  btUnionFind::allocate(a3, (int)this, N);
  for ( i = 0; i < N; ++i )
  {
    this->m_elements.m_data[i].m_id = i;
    this->m_elements.m_data[i].m_sz = 1;
  }
}
