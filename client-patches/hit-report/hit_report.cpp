#include <windows.h>

#include <float.h>
#include <stddef.h>
#include <string.h>

namespace {

enum match_client_synthetic_message_types_enum {
	client_player_hit = 0x4b
};

enum {
	payload_version					= 1,
	preferred_image_base			= 0x00010000,
	expected_pe_timestamp			= 0x518e2ed6,
	expected_image_size				= 0x04d43000,
	network_client_vtable_va		= 0x0096cc3c,
	player_hit_vtable_offset		= 0x30,
	empty_player_hit_handler_va		= 0x00022c50,
	network_match_client_offset		= 0x0a88,
	match_client_send_flag_offset	= 0x239c,
	current_player_offset			= 0x08,
	player_id_offset				= 0x34,
	sync_status_guard_va			= 0x005c5ab4,
	respawn_status_guard_va			= 0x005c5c48,
	new_packet_va					= 0x0075c8b0,
	enqueue_packet_va				= 0x0075cf90,
	packet_buffer_offset			= 0x31,
	max_packet_payload				= 240
};

struct fixed_string_16 {
	char*	begin;
	char*	end;
	char*	max_end;
	char	storage[16];
};

struct hit_info {
	fixed_string_16	body_part_name;
	fixed_string_16	damage_type;
	void*			bullet;
	float			amount;
	float			armor_piercing;
	unsigned char	hit_initiator;
	unsigned char	being_hit;
	unsigned char	padding[2];
};

typedef char assert_pointer_size_is_4[(sizeof(void*) == 4) ? 1 : -1];
typedef char assert_fixed_string_size[(sizeof(fixed_string_16) == 0x1c) ? 1 : -1];
typedef char assert_hit_info_size[(sizeof(hit_info) == 0x48) ? 1 : -1];
typedef char assert_amount_offset[(offsetof(hit_info, amount) == 0x3c) ? 1 : -1];
typedef char assert_initiator_offset[(offsetof(hit_info, hit_initiator) == 0x44) ? 1 : -1];

typedef void* (__thiscall* new_packet_function)(void*, unsigned char);
typedef void (__thiscall* enqueue_packet_function)(void*, void*);

HMODULE				g_executable;
void**				g_player_hit_slot;
void*				g_original_player_hit_handler;
bool				g_sync_status_guard_patched;
bool				g_respawn_status_guard_patched;

unsigned char const sync_status_guard_original[] = {
	0x83, 0xbd, 0x80, 0x41, 0x00, 0x00, 0x04, 0x75, 0x31
};
unsigned char const respawn_status_guard_original[] = {
	0x83, 0xbd, 0x80, 0x41, 0x00, 0x00, 0x04, 0x75, 0x20
};
unsigned char const disabled_status_guard[] = {
	0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
};

typedef char assert_status_guard_sizes_match[
	(sizeof(sync_status_guard_original) == sizeof(disabled_status_guard)
		&& sizeof(respawn_status_guard_original) == sizeof(disabled_status_guard)) ? 1 : -1
];

unsigned char* executable_address(const unsigned int preferred_va)
{
	return reinterpret_cast<unsigned char*>(g_executable)
		+ preferred_va - preferred_image_base;
}

bool is_expected_executable()
{
	unsigned char* const base = reinterpret_cast<unsigned char*>(g_executable);
	IMAGE_DOS_HEADER const* const dos = reinterpret_cast<IMAGE_DOS_HEADER const*>(base);
	if (dos->e_magic != IMAGE_DOS_SIGNATURE)
		return false;

	IMAGE_NT_HEADERS const* const nt =
		reinterpret_cast<IMAGE_NT_HEADERS const*>(base + dos->e_lfanew);
	if (nt->Signature != IMAGE_NT_SIGNATURE)
		return false;

	return nt->FileHeader.Machine == IMAGE_FILE_MACHINE_I386
		&& nt->FileHeader.TimeDateStamp == expected_pe_timestamp
		&& nt->OptionalHeader.SizeOfImage == expected_image_size;
}

bool replace_code(
	const unsigned int preferred_va,
	unsigned char const* const expected,
	unsigned char const* const replacement,
	const unsigned int size
)
{
	unsigned char* const address = executable_address(preferred_va);
	if (memcmp(address, expected, size) != 0)
		return false;

	DWORD old_protection = 0;
	if (!VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &old_protection))
		return false;

	memcpy(address, replacement, size);

	DWORD ignored = 0;
	VirtualProtect(address, size, old_protection, &ignored);
	FlushInstructionCache(GetCurrentProcess(), address, size);
	return true;
}

void restore_status_guards()
{
	if (g_respawn_status_guard_patched) {
		if (replace_code(
			respawn_status_guard_va,
			disabled_status_guard,
			respawn_status_guard_original,
			sizeof(respawn_status_guard_original)
		))
			g_respawn_status_guard_patched = false;
	}

	if (g_sync_status_guard_patched) {
		if (replace_code(
			sync_status_guard_va,
			disabled_status_guard,
			sync_status_guard_original,
			sizeof(sync_status_guard_original)
		))
			g_sync_status_guard_patched = false;
	}
}

bool install_timer_free_control()
{
	if (!replace_code(
		sync_status_guard_va,
		sync_status_guard_original,
		disabled_status_guard,
		sizeof(sync_status_guard_original)
	))
		return false;
	g_sync_status_guard_patched = true;

	if (!replace_code(
		respawn_status_guard_va,
		respawn_status_guard_original,
		disabled_status_guard,
		sizeof(respawn_status_guard_original)
	)) {
		restore_status_guards();
		return false;
	}
	g_respawn_status_guard_patched = true;
	return true;
}

unsigned char bounded_string_length(char const* const string, const unsigned char capacity)
{
	unsigned char length = 0;
	while (length < capacity && string[length])
		++length;
	return length;
}

bool append_bytes(void* const packet, void const* const bytes, const unsigned int size)
{
	unsigned char** const buffer = reinterpret_cast<unsigned char**>(packet);
	unsigned int* const buffer_size =
		reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(packet) + 4);

	if (*buffer != reinterpret_cast<unsigned char*>(packet) + packet_buffer_offset
		|| *buffer_size > max_packet_payload
		|| size > max_packet_payload - *buffer_size)
		return false;

	memcpy(*buffer + *buffer_size, bytes, size);
	*buffer_size += size;
	return true;
}

bool append_u8(void* const packet, const unsigned char value)
{
	return append_bytes(packet, &value, sizeof(value));
}

bool append_f32(void* const packet, const float value)
{
	return append_bytes(packet, &value, sizeof(value));
}

bool append_string(
	void* const packet,
	char const* const string,
	const unsigned char capacity
)
{
	unsigned char const length = bounded_string_length(string, capacity);
	return append_u8(packet, length) && append_bytes(packet, string, length);
}

bool is_local_player_hit(void* const network_client, hit_info const& info)
{
	void* const current_player = *reinterpret_cast<void**>(
		reinterpret_cast<unsigned char*>(network_client) + current_player_offset
	);
	if (!current_player)
		return false;

	unsigned char const current_player_id = *reinterpret_cast<unsigned char*>(
		reinterpret_cast<unsigned char*>(current_player) + player_id_offset
	);
	return current_player_id == info.hit_initiator;
}

void __fastcall report_player_hit(
	void* const network_client,
	void*,
	hit_info const* const info
)
{
	if (!network_client || !info || !is_local_player_hit(network_client, *info))
		return;

	if (!_finite(info->amount) || !_finite(info->armor_piercing)
		|| info->amount < 0.0f || info->armor_piercing < 0.0f)
		return;

	void* const match_client =
		reinterpret_cast<unsigned char*>(network_client) + network_match_client_offset;

	new_packet_function const new_packet =
		reinterpret_cast<new_packet_function>(executable_address(new_packet_va));
	void* const packet = new_packet(
		match_client,
		static_cast<unsigned char>(client_player_hit)
	);
	if (!packet)
		return;

	bool const serialized =
		append_u8(packet, payload_version)
		&& append_u8(packet, info->hit_initiator)
		&& append_u8(packet, info->being_hit)
		&& append_string(packet, info->body_part_name.storage, 15)
		&& append_string(packet, info->damage_type.storage, 15)
		&& append_f32(packet, info->amount)
		&& append_f32(packet, info->armor_piercing);

	// The fixed-size UDP packet has ample room for this bounded payload. A
	// failure indicates an incompatible packet layout, so do not enqueue it.
	if (!serialized)
		return;

	enqueue_packet_function const enqueue_packet =
		reinterpret_cast<enqueue_packet_function>(executable_address(enqueue_packet_va));
	enqueue_packet(match_client, packet);

	*reinterpret_cast<unsigned char*>(
		reinterpret_cast<unsigned char*>(match_client) + match_client_send_flag_offset
	) = 1;
}

bool install_hook()
{
	g_executable = GetModuleHandleA(NULL);
	if (!g_executable || !is_expected_executable())
		return false;

	g_player_hit_slot = reinterpret_cast<void**>(
		executable_address(network_client_vtable_va + player_hit_vtable_offset)
	);
	void* const expected_handler = executable_address(empty_player_hit_handler_va);
	if (*g_player_hit_slot != expected_handler)
		return false;
	if (!install_timer_free_control())
		return false;

	DWORD old_protection = 0;
	if (!VirtualProtect(
			g_player_hit_slot,
			sizeof(*g_player_hit_slot),
			PAGE_READWRITE,
			&old_protection
		)) {
		restore_status_guards();
		return false;
	}

	g_original_player_hit_handler = *g_player_hit_slot;
	*g_player_hit_slot = reinterpret_cast<void*>(&report_player_hit);

	DWORD ignored = 0;
	VirtualProtect(
		g_player_hit_slot,
		sizeof(*g_player_hit_slot),
		old_protection,
		&ignored
	);
	FlushInstructionCache(GetCurrentProcess(), g_player_hit_slot, sizeof(*g_player_hit_slot));
	return true;
}

void uninstall_hook()
{
	if (!g_player_hit_slot || !g_original_player_hit_handler
		|| *g_player_hit_slot != reinterpret_cast<void*>(&report_player_hit)) {
		restore_status_guards();
		return;
	}

	DWORD old_protection = 0;
	if (!VirtualProtect(
			g_player_hit_slot,
			sizeof(*g_player_hit_slot),
			PAGE_READWRITE,
			&old_protection
		)) {
		restore_status_guards();
		return;
	}

	*g_player_hit_slot = g_original_player_hit_handler;

	DWORD ignored = 0;
	VirtualProtect(
		g_player_hit_slot,
		sizeof(*g_player_hit_slot),
		old_protection,
		&ignored
	);
	FlushInstructionCache(GetCurrentProcess(), g_player_hit_slot, sizeof(*g_player_hit_slot));
	restore_status_guards();
}

} // namespace

BOOL WINAPI DllMain(HINSTANCE const instance, DWORD const reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(instance);
		if (!install_hook()) {
			OutputDebugStringA("SRP hit-report patch: unsupported executable or hook mismatch\n");
			return FALSE;
		}
		OutputDebugStringA("SRP hit-report patch installed\n");
	} else if (reason == DLL_PROCESS_DETACH) {
		uninstall_hook();
	}
	return TRUE;
}
