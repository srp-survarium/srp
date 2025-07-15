void __userpurge vostok::fixed_vector<unsigned short,1024>::fixed_vector<unsigned short,1024>(
        vostok::fixed_vector<unsigned short,1024> *this@<esi>,
        unsigned __int16 **last@<ecx>,
        unsigned __int16 **first)
{
  this->m_begin = (unsigned __int16 *)this->m_buffer;
  this->m_end = (unsigned __int16 *)this->m_buffer;
  this->m_max_end = (unsigned __int16 *)&this[1];
  vostok::buffer_vector<unsigned short>::assign<unsigned short const *>(*first, last, this);
}


void __usercall vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024>::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024>(
        vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024> *this@<eax>,
        const vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024> *other@<edx>)
{
  vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024>::allign_helper *m_buffer; // ecx
  vostok::particle::render_particle_emitter_instance **m_end; // esi
  vostok::particle::render_particle_emitter_instance **m_begin; // edx

  m_buffer = this->m_buffer;
  this->m_end = (vostok::particle::render_particle_emitter_instance **)this->m_buffer;
  this->m_begin = (vostok::particle::render_particle_emitter_instance **)this->m_buffer;
  this->m_max_end = (vostok::particle::render_particle_emitter_instance **)&this[1];
  m_end = other->m_end;
  m_begin = other->m_begin;
  this->m_end = (vostok::particle::render_particle_emitter_instance **)&this->m_buffer[m_end - m_begin];
  while ( m_begin != m_end )
  {
    if ( m_buffer )
      *m_buffer = (vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024>::allign_helper)*m_begin;
    ++m_begin;
    ++m_buffer;
  }
}


void __usercall vostok::fixed_vector<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,16>::fixed_vector<fastdelegate::FastDelegate<bool __cdecl (vostok::ui::window *,int,int)>,16>(
        vostok::fixed_vector<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>,16> *this@<eax>,
        const vostok::fixed_vector<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>,16> *other@<edx>)
{
  vostok::fixed_vector<fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)>,16>::allign_helper *m_buffer; // ecx
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *m_end; // esi
  fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *m_begin; // edx

  m_buffer = this->m_buffer;
  this->m_end = (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *)this->m_buffer;
  this->m_begin = (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *)this->m_buffer;
  this->m_max_end = (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *)&this[1];
  m_end = other->m_end;
  m_begin = other->m_begin;
  this->m_end = (fastdelegate::FastDelegate<bool __cdecl(vostok::ui::window *,int,int)> *)&this->m_buffer[m_end - m_begin];
  while ( m_begin != m_end )
  {
    if ( m_buffer )
    {
      *(_DWORD *)m_buffer->m_store = 0;
      *(_DWORD *)&m_buffer->m_store[4] = 0;
      *(_DWORD *)&m_buffer->m_store[4] = m_begin->m_Closure.m_pFunction;
      *(_DWORD *)m_buffer->m_store = m_begin->m_Closure.m_pthis;
    }
    ++m_begin;
    ++m_buffer;
  }
}
