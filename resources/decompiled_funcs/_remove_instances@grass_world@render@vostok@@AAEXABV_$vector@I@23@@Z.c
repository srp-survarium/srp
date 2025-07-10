void __userpurge vostok::render::grass_world::remove_instances(
        const vostok::render::vector<unsigned int> *v@<eax>,
        vostok::render::grass_world *this)
{
  unsigned int *M_start; // esi
  unsigned int *M_finish; // edi

  M_start = v->_M_impl._M_start;
  M_finish = v->_M_impl._M_finish;
  if ( v->_M_impl._M_start != M_finish )
  {
    do
      vostok::render::grass_world::remove_instance((vostok::render::grass_world *)*M_start++, (int)this);
    while ( M_start != M_finish );
  }
}
