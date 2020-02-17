#Running an asyncio Program 

import asyncio

async def main():
	await asyncio.sleep(1)
	print('hello')
	
asyncio.run(main())
