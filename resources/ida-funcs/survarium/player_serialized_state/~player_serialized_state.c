void __usercall survarium::player_serialized_state::~player_serialized_state(
        survarium::player_serialized_state *this@<ecx>,
        vostok::intrusive_list<vostok::network_core::buffer_writer::serialization_operation_descriptor,vostok::network_core::buffer_writer::serialization_operation_descriptor *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *a2@<edi>)
{
  vostok::network_core::mutable_buffer *v2; // ecx

  vostok::network_core::buffer_writer::~buffer_writer((vostok::network_core::buffer_writer *)this, a2 + 129);
  vostok::network_core::mutable_buffer::~mutable_buffer(v2, &a2[128].m_size);
}
