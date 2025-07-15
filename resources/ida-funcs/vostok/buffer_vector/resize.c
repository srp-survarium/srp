void __usercall vostok::buffer_vector<long volatile>::resize(
        vostok::buffer_vector<long volatile > *this@<ecx>,
        _DWORD *a2@<edi>)
{
  if ( (a2[1] - *a2) >> 2 )
    a2[1] = *a2;
}


void __usercall vostok::buffer_vector<vostok::render::stage *>::resize(
        vostok::buffer_vector<vostok::render::stage *> *this@<ecx>,
        int *a2@<edi>)
{
  int v2; // ecx
  unsigned int v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // ecx
  _DWORD *v6; // edx
  _DWORD *i; // eax

  v2 = *a2;
  v3 = (a2[1] - *a2) >> 2;
  if ( v3 != 29 )
  {
    if ( v3 <= 0x1D )
    {
      v4 = (_DWORD *)(v2 + 116);
      v5 = (_DWORD *)(v2 + 4 * v3);
      if ( v5 != v4 )
      {
        v6 = v5 + 1;
        do
        {
          for ( i = v5; i != v6; ++i )
          {
            if ( i )
              *i = 0;
          }
          ++v5;
          ++v6;
        }
        while ( v5 != v4 );
      }
      a2[1] = *a2 + 116;
    }
    else
    {
      a2[1] = v2 + 116;
    }
  }
}


void __thiscall vostok::buffer_vector<vostok::apc::callback>::resize(
        vostok::buffer_vector<vostok::apc::callback> *this)
{
  unsigned int v1; // eax
  bool v2; // cc
  unsigned int v3; // eax
  vostok::apc::callback *end; // [esp+0h] [ebp-4h] BYREF

  end = (vostok::apc::callback *)this;
  v1 = g_threads.m_end - g_threads.m_begin;
  v2 = v1 <= 0xB;
  if ( v1 != 11 )
  {
    v3 = v1;
    if ( v2 )
    {
      end = g_threads.m_begin + 11;
      vostok::buffer_vector<vostok::apc::callback>::construct(&g_threads.m_begin[v3], &end);
    }
    else
    {
      end = &g_threads.m_begin[v3];
      vostok::buffer_vector<vostok::apc::callback>::destroy(g_threads.m_begin + 11, &end);
    }
    g_threads.m_end = g_threads.m_begin + 11;
  }
}


void __userpurge vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::resize(
        unsigned int size@<eax>,
        vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc> *this)
{
  vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc> *v2; // ebx
  vostok::render::grass_layer_desc::model_desc *m_begin; // esi
  int v4; // ecx
  unsigned int v5; // edi

  v2 = this;
  m_begin = this->m_begin;
  v4 = (char *)this->m_end - (char *)this->m_begin;
  if ( size != v4 / 280 )
  {
    if ( size >= v4 / 280 )
    {
      v5 = size;
      this = (vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc> *)&m_begin[size];
      vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::construct(
        &m_begin[v4 / 280],
        (vostok::render::grass_layer_desc::model_desc *const *)&this);
      v2->m_end = &v2->m_begin[v5];
    }
    else
    {
      this->m_end = &m_begin[size];
    }
  }
}


void __fastcall vostok::buffer_vector<vostok::resources::request>::resize(
        int a1,
        unsigned int size,
        vostok::buffer_vector<vostok::resources::request> *this)
{
  vostok::resources::request *m_begin; // ecx
  unsigned int v4; // eax
  unsigned int v5; // ebx
  vostok::resources::request *v6; // edi
  vostok::resources::request *v7; // eax
  vostok::resources::request *v8; // esi

  m_begin = this->m_begin;
  v4 = this->m_end - this->m_begin;
  if ( size != v4 )
  {
    if ( size >= v4 )
    {
      v5 = size;
      v6 = &m_begin[size];
      v7 = &m_begin[v4];
      if ( v7 != v6 )
      {
        do
        {
          v8 = v7 + 1;
          survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_begin);
          v7 = v8;
        }
        while ( v8 != v6 );
      }
      this->m_end = &this->m_begin[v5];
    }
    else
    {
      this->m_end = &m_begin[size];
    }
  }
}


void __thiscall vostok::buffer_vector<vostok::render::vertex_colored>::resize(
        vostok::buffer_vector<vostok::render::vertex_colored> *this,
        vostok::buffer_vector<vostok::render::vertex_colored> *size)
{
  vostok::render::vertex_colored *m_begin; // edx
  unsigned int v3; // eax
  int v4; // ecx
  vostok::render::vertex_colored *v5; // eax
  vostok::render::vertex_colored *v6; // edi
  vostok::render::vertex_colored *v7; // edx
  vostok::render::vertex_colored *v8; // esi
  vostok::render::vertex_colored *i; // eax

  m_begin = size->m_begin;
  v3 = size->m_end - size->m_begin;
  if ( this != (vostok::buffer_vector<vostok::render::vertex_colored> *)v3 )
  {
    if ( (unsigned int)this >= v3 )
    {
      v4 = (int)this;
      v5 = &m_begin[v3];
      v6 = &m_begin[v4];
      v7 = v5;
      if ( v5 != v6 )
      {
        v8 = v5 + 1;
        do
        {
          for ( i = v7; i != v8; ++i )
          {
            if ( i )
              i->color.m_value = -1;
          }
          ++v7;
          ++v8;
        }
        while ( v7 != v6 );
      }
      size->m_end = &size->m_begin[v4];
    }
    else
    {
      size->m_end = &m_begin[(_DWORD)this];
    }
  }
}


void __thiscall vostok::buffer_vector<vostok::render::sampler_slot>::resize(
        vostok::buffer_vector<vostok::render::sampler_slot> *this,
        vostok::buffer_vector<vostok::render::sampler_slot> *size)
{
  vostok::render::sampler_slot *m_begin; // esi
  unsigned int v3; // eax
  int v4; // edi
  vostok::render::texture_slot *v5; // ebx
  vostok::render::texture_slot *v6; // eax
  vostok::render::texture_slot *v7; // esi

  m_begin = size->m_begin;
  v3 = size->m_end - size->m_begin;
  if ( this != (vostok::buffer_vector<vostok::render::sampler_slot> *)v3 )
  {
    if ( (unsigned int)this >= v3 )
    {
      v4 = (int)this;
      v5 = (vostok::render::texture_slot *)&m_begin[(_DWORD)this];
      v6 = (vostok::render::texture_slot *)&m_begin[v3];
      if ( v6 != v5 )
      {
        do
        {
          v7 = v6 + 1;
          vostok::memory::detail::call_constructor_helper<vostok::render::sampler_slot,0>::call(v6, v6 + 1);
          v6 = v7;
        }
        while ( v7 != v5 );
      }
      size->m_end = &size->m_begin[v4];
    }
    else
    {
      size->m_end = &m_begin[(_DWORD)this];
    }
  }
}


void __usercall vostok::buffer_vector<vostok::render::texture_slot>::resize(
        vostok::buffer_vector<vostok::render::texture_slot> *this@<edi>,
        unsigned int size@<eax>,
        vostok::render::texture_slot *a3@<ecx>)
{
  vostok::render::texture_slot *m_begin; // ecx
  unsigned int v5; // eax
  unsigned int v6; // esi
  unsigned int v7; // esi
  vostok::render::texture_slot *v8; // ebp
  vostok::render::texture_slot *v9; // eax
  vostok::render::texture_slot *v10; // ebx
  vostok::render::texture_slot *end; // [esp+0h] [ebp-4h] BYREF

  end = a3;
  m_begin = this->m_begin;
  v5 = this->m_end - this->m_begin;
  if ( size != v5 )
  {
    if ( size >= v5 )
    {
      v7 = size;
      v8 = &m_begin[v7];
      v9 = &m_begin[v5];
      if ( v9 != &m_begin[v7] )
      {
        do
        {
          v10 = v9 + 1;
          vostok::memory::detail::call_constructor_helper<vostok::render::sampler_slot,0>::call(v9, v9 + 1);
          v9 = v10;
        }
        while ( v10 != v8 );
      }
      this->m_end = &this->m_begin[v7];
    }
    else
    {
      v6 = size;
      end = &m_begin[v5];
      vostok::buffer_vector<vostok::render::texture_slot>::destroy(&m_begin[v6], &end);
      this->m_end = &this->m_begin[v6];
    }
  }
}


void __userpurge vostok::buffer_vector<vostok::tasks::thread_tls>::resize(
        vostok::buffer_vector<vostok::tasks::thread_tls> *this@<ecx>,
        int *a2@<esi>,
        unsigned int size)
{
  int v3; // ecx
  unsigned int v4; // ebx
  int v5; // edi
  int v6; // eax

  v3 = *a2;
  v4 = size;
  v5 = a2[1] - *a2;
  v6 = v5 / 360;
  if ( size != v5 / 360 )
  {
    if ( size >= v5 / 360 )
    {
      size = 360 * size + v3;
      vostok::buffer_vector<vostok::tasks::thread_tls>::construct(
        (vostok::tasks::thread_tls *)(v3 + 360 * v6),
        (vostok::tasks::thread_tls *const *)&size);
    }
    else
    {
      size = v3 + 360 * v6;
      vostok::buffer_vector<vostok::tasks::thread_tls>::destroy(
        (vostok::tasks::thread_tls *)(360 * v4 + v3),
        (vostok::tasks::thread_tls *const *)&size);
    }
    a2[1] = 360 * v4 + *a2;
  }
}


void __usercall vostok::buffer_vector<vostok::render::vector<vostok::math::frustum>>::resize(
        vostok::buffer_vector<vostok::render::vector<vostok::math::frustum> > *this@<esi>,
        unsigned int size@<eax>,
        vostok::render::vector<vostok::math::frustum> *a3@<ecx>)
{
  vostok::render::vector<vostok::math::frustum> *m_begin; // ecx
  bool v5; // cf
  int v6; // eax
  unsigned int v7; // edi
  vostok::render::vector<vostok::math::frustum> *end; // [esp+0h] [ebp-4h] BYREF

  end = a3;
  m_begin = this->m_begin;
  v5 = size < this->m_end - this->m_begin;
  if ( size != this->m_end - this->m_begin )
  {
    v6 = this->m_end - this->m_begin;
    if ( v5 )
    {
      v7 = size;
      end = &m_begin[this->m_end - this->m_begin];
      vostok::buffer_vector<vostok::render::vector<vostok::math::frustum>>::destroy(&m_begin[v7], &end);
      this->m_end = &this->m_begin[v7];
    }
    else
    {
      end = &m_begin[size];
      vostok::buffer_vector<vostok::render::vector<vostok::render::culling::aab_rect>>::construct(&m_begin[v6], &end);
      this->m_end = &this->m_begin[size];
    }
  }
}
