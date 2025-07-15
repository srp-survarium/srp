void __usercall vostok::render::skeleton_mesh_gpu_skinning_4weights::skeleton_mesh_gpu_skinning_4weights(
        vostok::render::skeleton_mesh_gpu_skinning_4weights *this@<ecx>,
        unsigned int **a2@<esi>)
{
  vostok::render::render_surface::render_surface(this, (int)a2);
  a2[1] = (unsigned int *)3;
  *a2 = &stru_966A14.m_mem_usage;
  a2[39] = 0;
}
