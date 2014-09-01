#pragma once

#define V8_ENTER_SCOPE()	v8::Isolate* isolate = v8::Isolate::GetCurrent();\
							v8::Isolate::Scope isolateScope( isolate );\
							v8::HandleScope handleScope( isolate );
#define V8_CALLBACK_INIT( args )	v8::Local< v8::Object > gameObject = args.Holder();\
									Gunship* gunship = static_cast< Gunship* >( v8::Local< v8::External >::Cast( gameObject->Get( v8::String::NewFromUtf8( isolate, "gunship" ) )->ToObject()->GetInternalField( 0 ) )->Value() );

#define V8_FUNCTION_TEMPLATE( isolate, value ) v8::FunctionTemplate::New( isolate, value )
#define V8_UNSIGNED( isolate, value ) v8::Integer::NewFromUnsigned( isolate, value )
#define V8_STRING( isolate, string ) v8::String::NewFromUtf8( isolate, string )
#define V8_BOOL( isolate, value ) v8::Boolean::New( isolate, value )

#define V8_GET_UNSIGNED( isolate, object, param ) object->Get( V8_STRING( isolate, param ) )->Uint32Value()